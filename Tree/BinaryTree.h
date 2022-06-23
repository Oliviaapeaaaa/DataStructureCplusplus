//
// Created by Oliviaaaaa on 6/23/22.
//
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include "BinaryTreeNode.cpp"
#ifndef DSC___BINARYTREE_H
#define DSC___BINARYTREE_H
// if there is no access specifier）
// class:  private，
// struct: public
using namespace std;
struct BinaryTreeNode{
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* parent;
    BinaryTreeNode* next;
    int count;


    BinaryTreeNode(int d)
        : data(d),
        left(nullptr),
        right(nullptr),
        next(nullptr),
        parent(nullptr),
        count(0) {}
};

class BinaryTree {
public :
    BinaryTreeNode*  root;
// constructor
    BinaryTree(){
    root = nullptr;
    };

    BinaryTree(int node_data){
        root = new BinaryTreeNode(node_data);
    }

    BinaryTree(vector<int>& v) {
        root = nullptr;
        for (int x : v) {
            Insert(x);
        }
    }

    void Insert(int node_data){
        BinaryTreeNode* new_node = new BinaryTreeNode(node_data);
        if (root == nullptr){
            root = new_node;
        } else {
            BinaryTreeNode* parent = nullptr;
            BinaryTreeNode* temp = root;
            while (temp != nullptr){
                parent = temp;
                if (node_data <= temp->data){
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }

            }
            if (node_data <= parent->data){
                parent->left = new_node;
            } else {
                parent->right = new_node;
            }
        }
    }

    void InsertInorder(int node_data) {
        queue<BinaryTreeNode*> tempQueue;
        BinaryTreeNode* temp = root;
        tempQueue.push(temp);

        while (!tempQueue.empty()) {
            temp = tempQueue.front();
            tempQueue.pop();

            if (temp->left == nullptr) {
                temp->left = new BinaryTreeNode(node_data);
                break;
            } else {
                tempQueue.push(temp->left);
            }

            if (temp->right == nullptr) {
                temp->right = new BinaryTreeNode(node_data);
                break;
            } else {
                tempQueue.push(temp->right);
            }
        }
    }





}


#endif //DSC___BINARYTREE_H
