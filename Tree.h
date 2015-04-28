#ifndef __TREE_H__
#define __TREE_H__

#include <stdlib.h>
#include "Linked_List.h"
#include "Stack.h"

template <class type>

class TreeNode {

	public:
		
		//Attributes
		type data;
		TreeNode* parent;
		p2List <TreeNode*> children;

		//Constructors
		TreeNode(const type &_data){
			data = _data;
			parent = NULL;
		}

		TreeNode(){
			data = NULL;
			parent = NULL;
		}

		void AddChild(TreeNode* child){
		
			children.add(child);
			child->parent = this;
		
		}

		bool RemoveChild(TreeNode* child)
		{
			bool ret = false;
			p2List_item <TreeNode*>* tmp = children.getFirst();

			for (; tmp != NULL; tmp = tmp->next)
			{
				TreeNode* son = tmp->data;

				if (child == son)
				{
					children.del(tmp);
					child->parent = NULL;
					ret = true;
					break;
				}
			}

			return ret;
		}


		void PreOrderRecursive(p2List <TreeNode<type>*>* list){

			list->add(this);

			p2List_item <TreeNode*>* tmp = children.getFirst();
			while (tmp != NULL){

				tmp->data->PreOrderRecursive(list);
				tmp = tmp->next;
			}

		}

		
		void InOrderRecursive(p2List <TreeNode<type>*>* list){

			p2List_item <TreeNode*>* child = children.getFirst();
			int num = children.count() / 2;
			for (int i = 0; i < num; i++){
				child->data->InOrderRecursive(list);
				child = child->next;
			}

			list->add(this);

			while (child != NULL)
			{
				child->data->InOrderRecursive(list);
				child = child->next;
			}		
		}
	

		void PostOrderRecursive(p2List <TreeNode <type>*>* list){

			p2List_item <TreeNode*>* tmp = children.getFirst();

			while (tmp != NULL){

				tmp->data->PostOrderRecursive(list);
				tmp = tmp->next;
			}

			list->add(this);
		}

		//Ricard's functions
		TreeNode<type>* FindRecursive(const type& node)
		{
			if (node == data)
				return this;

			TreeNode<type>* result = NULL;
			p2List_item<TreeNode*>* item = children.getFirst();
			for (; item != NULL; item = item->next)
			{
				TreeNode* child = item->data;
				result = child->FindRecursive(node);

				if (result != NULL)
					break;
			}

			return result;
		}

		void GatherAll(p2List<TreeNode*>* list)
		{

			list->add(this);

			p2List_item <TreeNode*>* item = children.getFirst();

			for (; item != NULL; item = item->next)
			{
				TreeNode* child = item->data;
				child->GatherAll(list);
			}
		}
};

//Lacking iterative method InOrder. Although I've tried it, I can't manage to make it function properly

template <class type>

class Tree {

	public:

		//Attributes
		TreeNode <type>* root;

		//Constructors
		Tree() {
		
			root = NULL;
		}

		Tree(const type &_data) {
		
			root->data = _data;
			root->parent = NULL;

		}

		//Methods:
		
		//Recursive
		void PreOrderRecursive(p2List <TreeNode<type>*>* list) const{

			root->PreOrderRecursive(list);
		}
		
		void InOrderRecursive(p2List <TreeNode<type>*>* list) const{

			root->InOrderRecursive(list);
		}

		void PostOrderRecursive(p2List <TreeNode<type>*>* list) const{

			root->PostOrderRecursive(list);
		}

		//Iterative
		void PreOrderIterative(p2List <TreeNode<type>*>* list){

			Stack <TreeNode <type>*> stack;
			
			TreeNode <type>* tmp = root;

			while (tmp != NULL){

				list->add(tmp);
				p2List_item <TreeNode <type>*>* child = tmp->children.getLast();
			
				
				while (child != tmp->children.getFirst()) {

					stack.Push(child->data);
					child = child->prev;
				}

				if (child != NULL) {
					
					tmp = child->data;
				}

				else {
					tmp = NULL;
				}

			}
		}

		void PostOrderIterative(p2List <TreeNode<type>*>* list)
		{
			Stack <TreeNode<type>*> stack;
			TreeNode <type>* tmp = root;

			while (tmp != NULL)
			{
				p2List_item <TreeNode<type>*>* child = tmp->children.getLast();

				if (tmp != NULL && list->find(child->data) == -1)
				{
					stack.Push(tmp);

					while (child != tmp->children.getFirst()){

						stack.Push(child->data);
						child = child->prev;
					}


					tmp = child->data;
				}

				else
				{
					list->add(tmp);
					tmp = NULL;
				}

			}

		}

		void Add(const type &_data){

			TreeNode <type>* child = new TreeNode<type>(child);
			root->AddChild(child);
		}

		
		void Add(const type &_data, const type &_parent)
		{
			TreeNode<type>* father = root->FindRecursive(_parent);
			TreeNode<type>* child = new TreeNode<type>(_data);
			father->AddChild(child);
		}
		//https://github.com/laura-96/Practica_2.git
		

		void Clear(){
			
			p2List <TreeNode <type>*> nodes_to_delete;
			root->GatherAll(&nodes_to_delete);

			p2List_item <TreeNode<type>*>* item = nodes_to_delete.getFirst();

			for (; item != NULL; item = item->next){

				TreeNode<type>* child = item->data;

				if (child->parent)
				{
					child->parent->RemoveChild(child);
				}
			}
		}


		//Destructor
		~Tree()
		{
			Clear();
		}

};


#endif