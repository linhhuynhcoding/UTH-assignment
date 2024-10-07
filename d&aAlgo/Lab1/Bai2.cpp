#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <Windows.h>
using namespace std;
using namespace std::chrono_literals;

struct AVL
{
    int data;
    AVL *root = nullptr;
    AVL *left = nullptr;
    AVL *right = nullptr;
    int height = 0;
    int balanceFactor = 0;

    AVL()
    {
        AVL *root = nullptr;
        AVL *left = nullptr;
        AVL *right = nullptr;
    }
    AVL(int x)
    {
        this->root = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        // root = (AVL *)malloc(sizeof(AVL));
        // left = (AVL *)malloc(sizeof(AVL));
        // right = (AVL *)malloc(sizeof(AVL));
        this->data = x;
        this->height = 0;
        this->balanceFactor = 0;
    }

    bool insert(int x)
    {
        AVL *p = this;
        AVL *prev = nullptr;
        AVL *current = new AVL(x);

        while (p != nullptr)
        {
            prev = p;
            if (current->data < p->data)
            {
                p = p->left;
                if (p == nullptr)
                {
                    current->root = prev;
                    prev->left = current;
                    if (prev->root != nullptr)
                    {
                        if (prev->root->balanceFactor == -1 && prev->root->right == prev)
                        {
                            prev->rotateRight();
                            prev->root->rotateLeft();
                        }
                        else if (prev->root->balanceFactor == 1 && prev->root->left == prev)
                        {
                            prev->root->rotateRight();
                        }
                    }
                }
            }
            else
            {
                p = p->right;
                if (p == nullptr)
                {
                    current->root = prev;
                    prev->right = current;
                    if (prev->root != nullptr)
                    {
                        if (prev->root->balanceFactor == 1 && prev->root->left == prev)
                        {
                            prev->rotateLeft();
                            prev->root->rotateRight();
                        }
                        else if (prev->root->balanceFactor == -1 && prev->root->right == prev)
                        {
                            prev->root->rotateLeft();
                        }
                    }
                }
            }
        }
        return true;
    }

    bool search(int x)
    {
        AVL *p = this;

        while (p != nullptr)
        {
            if (x == p->data)
            {
                return true;
            }

            if (x < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }

        return false;
    }

    void outputLNR()
    {
        AVL *p = this;
        cout << p->data << "(" << p->balanceFactor << ")" << " ";

        if (p->left != nullptr)
            (p->left)->outputLNR();

        if (p->right != nullptr)
            (p->right)->outputLNR();
    }

    void updateHeight()
    {

        if (this->left != nullptr)
            this->left->updateHeight();
        if (this->right != nullptr)
            this->right->updateHeight();
        this->height = max((this->left != nullptr ? this->left->height : -1), (this->right != nullptr ? this->right->height : -1)) + 1;
        balanceFactor = (this->left != nullptr ? this->left->height : -1) - (this->right != nullptr ? this->right->height : -1);
    }

    void rotateLeft()
    {
        AVL *p = this;
        AVL *parent = p->root;
        AVL *newparent = p->right;

        if (parent != nullptr)
        {
            newparent->root = parent;
            if (parent->left == p)
            {
                parent->left = newparent;
            }
            else
            {
                parent->right = newparent;
            }
        }
        else
        {
            newparent->root = nullptr;
        }

        p->right = newparent->left;
        p->root = newparent;
        newparent->left = p;
    }

    void rotateRight()
    {
        AVL *p = this;
        AVL *parent = p->root;
        AVL *newparent = p->left;

        if (parent != nullptr)
        {
            newparent->root = parent;
            if (parent->left == p)
            {
                parent->left = newparent;
            }
            else
            {
                parent->right = newparent;
            }
        }
        else
        {
            newparent->root = nullptr;
        }

        p->left = newparent->right;
        p->root = newparent;
        newparent->right = p;
    }
};

struct LKL
{
    int data;
    LKL *next;

    LKL()
    {
    }

    LKL(int x)
    {
        this->data = x;
        this->next = nullptr;
    }

    bool insert(int x)
    {
        LKL *p = this;
        LKL *newp = new LKL(x);

        while (p->next != nullptr)
        {
            p = p->next;
        }

        p->next = newp;
        return true;
    }

    void output()
    {
        LKL *p = this;

        while (p->next != nullptr)
        {
            cout << p->data << " -> ";
            p = p->next;
        }

        cout << "nullptr\n";
    }

    bool search(int x)
    {
        LKL *p = this;

        while (p->next != nullptr)
        {
            if (p->data == x)
            {
                return true;
            }

            p = p->next;
        }

        return false;
    }
};

struct DataSet
{
    vector<int> data;

    DataSet(int size, int upbound)
    {
        for (int i = 0; i < size; i++)
        {
            data.push_back(this->sinhso(upbound));
        }
    }

    int sinhso(int upbound)
    {
        mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
        long long rand = rd() % 1000000 % upbound;

        return rand;
    }

    void output()
    {
        cout << "[";
        for (int i = 0; i < data.size(); i++)
        {
            cout << data[i] << ", ";

            if (i == 11) {
                cout << ".....";
                break;
            }

        }
        cout << "\b\b]\n";
    }
};

double dothoigian(int param, auto *s)
{
    const auto start{std::chrono::steady_clock::now()};
    s->search(param);
    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double, std::milli> elapsed_seconds{end - start};
    return elapsed_seconds.count();
}

void process(int size, int upbound)
{
    cout << "Tập dữ liệu Gồm " << size << " số được sinh ngẫu nhiêu khác nhau trong khoảng [1.." << upbound << "] : \n\t";
    DataSet *dataset = new DataSet(size, upbound);
    dataset->output();

    cout << "Sinh một số ngẫu nhiên : x = ";
    const int randomNumber = dataset->sinhso(upbound);
    cout << randomNumber << "\n\n";

    AVL *bst = new AVL(1);
    LKL *list = new LKL(1);
    for (auto i : dataset->data)
    {
        list->insert(i);
        bst->insert(i);
        while (bst->root != nullptr)
        {
            bst = bst->root;
        }
        bst->updateHeight();
    }
    // So sánh thực nghiệm kết quả
    cout << "Cây AVL : ";
    cout << dothoigian(randomNumber, bst) << " mili giây..\n";
    cout << "Danh sách liên kết : ";
    cout << dothoigian(randomNumber, list) << " mili giây..\n";
    cout << "-------------------------------\n";
}

int main()
{
    SetConsoleOutputCP(CP_UTF8); // Thư viện hỗ trợ in Tiếng Việt

    // Tập dữ liệu Gồm 10 số được sinh ngẫu nhiêu khác nhau trong khoảng [1..100]
    process(10, 100);
    // Tập dữ liệu Gồm 100 số được sinh ngẫu nhiêu khác nhau trong khoảng [1..1000]
    process(100, 1000);
    // Tập dữ liệu Gồm 1000 số được sinh ngẫu nhiêu khác nhau trong khoảng [1..10000]
    process(1000, 10000);
    // Tập dữ liệu Gồm 10000 số được sinh ngẫu nhiêu khác nhau trong khoảng [1..10000]
    process(10000, 100000);

    return 0;
}
