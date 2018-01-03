#include "circus.h"

Circus::Circus(std::string fileName) {
    m_fileName = fileName;
    //first pass: add nodes with name, weight and possible children
    firstPass();
    //second pass: add parent references to nodes
    secondPass();
    //third pass: check which node has no parent
    m_root = thirdPass();
    //fourth pass: count weight sums for all nodes
    fourthPass();
    //fifth pass: check which node has uneven child weights
    m_problemChild = fifthPass();
    //testPrint();
}

void Circus::testPrint() {
    for (std::pair<std::string, Prog*> prog : progMap) {
        std::cout << "Name/Weight: " << prog.first << "/" << prog.second->getWeightSum() << "\n";
    }
}

void Circus::firstPass() {
    std::ifstream fileStream(m_fileName);
    std::string line;
    while (std::getline(fileStream, line)){
        lineHandler(line);
    }
}

void Circus::secondPass() {
    //if the node has children
    for (std::pair<std::string, Prog*> prog : progMap) {
        //for every child
        for(std::string child : prog.second->getChildren()){
            //make this node their parent
            progMap[child]->addParent(prog.first);
        }
    }
}

std::string Circus::thirdPass() {
    for (std::pair<std::string, Prog*> prog : progMap) {
        if (prog.second->getParent().empty()) {
            return prog.first;
        }
    }

    return "problem in third pass";
}

void Circus::fourthPass() {
    for (std::pair<std::string, Prog*> prog : progMap) {
        travel(prog.second->getParent(), prog.second->getWeight());
    }
}

std::string Circus::fifthPass() {
    for (std::pair<std::string, Prog*> prog : progMap) {
        if (faultExists(prog.first)) {
            return faultyChild(prog.first);
        }
    }
    return "problem in fifth pass";
}

bool Circus::faultExists(std::string parent) {
    std::list<std::string> children = progMap[parent]->getChildren();
    int first = -1;
    for(std::string child : children) {
        if (first < 0) {
            first = progMap[child]->getWeightSum();
        } else {
            if (first != progMap[child]->getWeightSum()) {
                return true;
            }
        }
    }
    return false;
}

//walks down the tree to see which child node the fault originates from
std::string Circus::faultySubtree(std::string parent) {
    bool faultyChild = false;
    for (std::string child : progMap[parent]->getChildren()){
        if(faultExists(child)) {
            return faultySubtree(child);
        }
    }

    return parent;
}

//finds out which node is the "wrong" one within the subtree
std::string Circus::faultyChild(std::string parent) {
    parent = faultySubtree(parent);
    std::list<std::string> children = progMap[parent]->getChildren();
    //first child to not match with 2 children is the faulty one
    for (std::string child : children) {
        int fails = 0;
        for (std::string c : children) {
            if (progMap[child]->getWeightSum() != progMap[c]->getWeightSum()){
                fails++;
            }
        }
        if (fails > 1) {
            return child;
        }
    }
    return "no faults found";
}

void Circus::travel(std::string parent, int weight) {
    if (!parent.empty()) {
        progMap[parent]->addWeight(weight);
        travel(progMap[parent]->getParent(), weight);
    }
}

void Circus::lineHandler(std::string line) {
    std::stringstream lineStream(line);

    //we assume that every line has content and is formatted appropriately
    //first word is the name of the node(program)
    std::string name;
    lineStream >> name;

    //second word is the weight in paragraphs
    std::string str_weight;
    lineStream >> str_weight;
    int weight = parseWeight(str_weight);

    //create node(program)
    Prog *prog = new Prog(name, weight);

    //if there are more words, the first one is the arrow and rest are children
    std::string child;
    if (lineStream >> child) {
        while(lineStream >> child) {
            prog->addChild(parseChild(child));
        }
    } 
    //add it to the collection
    progMap[name] = prog;
}

std::string Circus::parseChild(std::string child) {
    std::size_t found = child.find(",", 0);
    if (found != std::string::npos) {
        child.erase(found, 1);
    }
    return child;
}

int Circus::parseWeight(std::string str_weight) {
    str_weight.erase(0,1);
    str_weight.erase(str_weight.size() - 1 ,1);
    return std::stoi(str_weight);
}

std::string Circus::bottom() {
    return m_root;
}

std::string Circus::unbalanced() {
    return m_problemChild;
}

int Circus::desiredWeight() {
    Prog *node = progMap[m_problemChild];
    for (std::string sibling : progMap[node->getParent()]->getChildren()){
        if (progMap[sibling]->getWeightSum() != node->getWeightSum()){
            std::cout << "Sibling: " << progMap[sibling]->getName() << "/" << progMap[sibling]->getWeightSum() << "\n";
            std::cout << "This node: " << node->getName() << "/" << node->getWeightSum() << "\n";
            return node->getWeight() - (node->getWeightSum() - progMap[sibling]->getWeightSum());
        }
    }
    return 0;
}