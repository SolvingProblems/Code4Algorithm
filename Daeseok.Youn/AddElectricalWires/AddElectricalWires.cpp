/*
 * TopCoder
 * Name : AddElectricalWires(250p)
 * This code could not be passing system tests.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AddElectricalWires {
public:
    bool checkOneorZero(vector<string> &wire, int xNode,
                        int yNode, vector<int> &gridCon) {
        int bothConnected = 0;
        bool getConncected = false;

        for (int i = 0; i < gridCon.size(); i++) {
            int main = gridCon.at(i);
            if (xNode == main || yNode == main) {
                bothConnected += main;
            }
        }

        for (int i = 0; i < wire.at(xNode).length(); i++) {
            if ((wire.at(yNode).at(i) == '2' && bothConnected == xNode) ||
                (wire.at(xNode).at(i) == '2' && bothConnected == yNode))
                return getConncected;
        }

        if ((wire.at(xNode).at(yNode) - '0' == 0 ||
            wire.at(yNode).at(xNode) - '0' == 0) &&
            bothConnected != (xNode + yNode)) {
            getConncected = true;

            if (bothConnected == xNode) {
                wire.at(yNode).at(xNode) = '2';
            }
        }

        return getConncected;
    }

    int maxNewWires(vector<string> wires,
                    vector<int> gridConnections) {
        if (wires.size() > 50 || wires.empty() ||
            gridConnections.size() >= wires.size())
            return 0;

        int maxWire = 0;
        int nodeCount = wires.at(0).length();

        for (int i = 0; i < wires.size(); i++) {
            for (int j = 0; j < nodeCount; j++) {
                if ((i != j) &&
                    checkOneorZero(wires, i, j,
                                   gridConnections)) {
                    wires.at(i).at(j) = '1';
                    if (wires.at(j).at(i) != '2')
                        wires.at(j).at(i) = '1';
                    maxWire += 1;
                }
            }
        }

        return maxWire;
    }

    void printVector(vector<string> map)
    {
        for (int i = 0; i < map.size(); i++)
            cout << " " << map.at(i);

        cout << endl;
    }

    void printVector(vector<int> map)
    {
        for (int i = 0; i < map.size(); i++)
            cout << " " << map.at(i);

        cout << endl;
    }
private:
};

int main(void)
{
    string input[] = {"000","000","000"};
    int inputGrid [] = {0};
    //int inputGrid [] = {0, 1};
    vector<string> wires;
    vector<int> grid;

    for (int i = 0; i < 3; i++)
        wires.push_back(input[i]);
    grid.push_back(inputGrid[0]);
    //grid.push_back(inputGrid[1]);

    AddElectricalWires aew;
    cout << aew.maxNewWires(wires, grid) << endl;

    return 0;
}
