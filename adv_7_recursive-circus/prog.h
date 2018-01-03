#pragma once

#include <string>
#include <list>


class Prog {
private:
    std::list<std::string> m_children;
    std::string m_parent;
    std::string m_name;
    int m_weight;
    int m_weightSum;

public:
    Prog(std::string name, int weight);

    void addParent(std::string parent);
    void addChild(std::string child);
    void addWeight(int weight);

    std::string getName();
    std::string getParent();
    int getWeight();
    int getWeightSum();
    std::list<std::string> getChildren();
};