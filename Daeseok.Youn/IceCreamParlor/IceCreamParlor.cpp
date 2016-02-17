#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class IceCreamParlor {
    public:
        IceCreamParlor() {
            root = NULL;
        };
        ~IceCreamParlor() {};

        vector<int> datas;

        void setAmount(int a) {
            amount = a;
        }

        int amount;

        typedef struct _Node {
            struct _Node *left;
            struct _Node *right;
            int data;
        } Node;

        typedef struct stackNode {
            Node *n;
            struct stackNode *next;
        } sNode;

        Node *root;

        void insertNode(int num) {
            Node *n = new Node;
            n->data = num;
            n->left = NULL;
            n->right = NULL;

            Node *temp = root;
            datas.push_back(num);

            if (root == NULL) {
                root = n;
                return;
            } else {
                while (1) {
                    if (temp->right != NULL &&
                        temp->data < num) {
                        temp = temp->right;
                    } else if (temp->left != NULL &&
                               temp->data >= num) {
                        temp = temp->left;
                    }

                    if ((temp->right == NULL && temp->data < num) ||
                        (temp->left == NULL && temp->data >= num))
                        break;
                }

                if (temp->data < num)
                    temp->right = n;
                else
                    temp->left = n;
            }
        }

        void findSolution() {
            int index = 0;

            while (index < datas.size()) {
                int temp = datas.at(index);
                int choosenIndex;

                choosenIndex = findNumFromBinTree(index, amount - temp);

                if (choosenIndex > 0) {
                    cout << index + 1 << " " << choosenIndex + 1 << endl;
                    break;
                }
                index++;
            }
        }

        int findIndex(int start, int num) {
            for (int i = start + 1; i < datas.size(); i++) {
                if (datas.at(i) == num)
                    return i;
            }

            return -1;
        }

        int findNumFromBinTree(int start, int num) {
            Node *temp = root;
            int fNum = 0;
            int index = -1;

            while (temp != NULL) {
                if (temp->data == num) {
                    fNum = num;
                    break;
                }

                if (temp->data < num)
                    temp = temp->right;
                else
                    temp = temp->left;
            }

            if (fNum != 0)
                index = findIndex(start, fNum);

            return index;
        }

        bool stackEmpty(sNode *last) {
            return (last == NULL) ? true : false;
        }

        void pushNode(sNode **last, Node *cur) {
            sNode *sItem = new sNode;

            sItem->n = cur;
            sItem->next = (*last);
            (*last) = sItem;
        }

        Node *popNode(sNode **last) {
            Node *node;
            sNode *sn;

            if (stackEmpty(*last)) {
                return NULL;
            } else {
                sn = *last;
                node = sn->n;
                *last = sn->next;
                delete sn;

                return node;
            }
        }

        void clearNodes() {
            sNode *s = NULL;
            Node *current = root;

            while (1) {
                if (current != NULL) {
                    pushNode(&s, current);
                    current = current->left;
                } else {
                    if (!stackEmpty(s)) {
                        current = popNode(&s);

                        Node *temp = current;
                        current = current->right;
                        if (temp != NULL)
                            delete temp;

                    } else {
                        break;
                    }
                }
            }

            root = NULL;
            datas.clear();
        }
};

int main() {
    int testCase = 0;
    int amount = 0;
    int arraySize = 0;
    IceCreamParlor icp;

    cin >> testCase;

    while (testCase-- > 0) {
        cin >> amount >> arraySize;

        icp.setAmount(amount);
        for (int i = 0; i < arraySize; i++) {
            int temp = 0;
            cin >> temp;

            icp.insertNode(temp);
        }

        icp.findSolution();
        icp.clearNodes();
    }

    return 0;
}
