#include "prog.h"

Prog::Prog(std::string name, int weight) {
    m_name = name;
    m_weight = weight;
    m_weightSum = weight;
    m_parent = "";
}

void Prog::addParent(std::string parent) {
    m_parent = parent;
}

void Prog::addChild(std::string child) {
    m_children.push_back(child);
}

void Prog::addWeight(int weight) {
    m_weightSum += weight;
}

std::string Prog::getName() {
    return m_name;
}

std::string Prog::getParent() {
    return m_parent;
}

int Prog::getWeight() {
    return m_weight;
}

int Prog::getWeightSum() {
    return m_weightSum;
}

std::list<std::string> Prog::getChildren() {
    return m_children;
}