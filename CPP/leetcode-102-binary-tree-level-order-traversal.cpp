#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution{
public:
	
	Solution();
	~Solution();
	bool insert(int key);//插入节点
	void printTree();//打印整棵树
	void destroyTree();//销毁树
	void levelOrder();//本文算法
	
private:
	bool insert(int key, TreeNode* leaf);
	void printTree(TreeNode* leaf);
	void destroyTree(TreeNode* leaf);
	vector<vector<int>> levelOrder(TreeNode * root);

	TreeNode* root;

};
Solution::Solution(){
	root = NULL;
}
bool Solution::insert(int key){
	if (root != NULL){
		return insert(key, root);
	}
	else{
		root = new TreeNode(key);
	}
	
}
bool Solution::insert(int key, TreeNode* node){
	if (key < node->val){
		if (node->left != NULL){
			return insert(key, node->left);
		}
		else{
			node->left = new TreeNode(key);
			return true;
		}
		
	}else if (key>node->val){
		if (node->right != NULL){
			return insert(key, node->right);
		}
		else{
			node->right = new TreeNode(key);
			return true;
		}
		
	}
	else{
		return false;
	}
}
void  Solution::levelOrder(){
	vector<vector<int>> levelOrder1 = levelOrder(root);
	for (int i = 0; i < levelOrder1.size(); i++){

		for (int j = 0; j < levelOrder1[i].size(); j++){
			cout << levelOrder1[i][j] << " ";
		}
		cout << endl;
	}
}
vector<vector<int>> Solution::levelOrder(TreeNode * root){
	vector<vector<int>> result;
	queue<TreeNode*> que;
	if (root != nullptr){
		que.emplace(root);
	}
	while (!que.empty()){
		vector<int> level;
		int size = que.size();
		for (int i = 0; i < size; i++){
			auto *front = que.front();
			que.pop();
			level.emplace_back(front->val);
			if (front->left != nullptr){
				que.emplace(front->left);
			}
			if (front->right != nullptr){
				que.emplace(front->right);
			}
		}
		result.emplace_back(move(level));
	}
	return result;
}
void Solution::printTree(){
	printTree(root);
}
void Solution::printTree(TreeNode* leaf){
	if (leaf != NULL){
		printTree(leaf->left);
		cout << leaf->val << " ";
		printTree(leaf->right);
	}
}
void Solution::destroyTree(){
	destroyTree(root);
}
void Solution::destroyTree(TreeNode* leaf){
	if (leaf != NULL){
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}
int main(){
	int i;
	Solution* binTree = new Solution();
	cout << binTree->insert(5) << endl;
	cout << binTree->insert(3) << endl;
	cout << binTree->insert(7) << endl;
	cout << binTree->insert(5) << endl;
	cout << binTree->insert(2) << endl;
	cout << binTree->insert(8) << endl;
	cout << binTree->insert(9) << endl;
	binTree->printTree();
	cout << endl;
	binTree->levelOrder();
	cout << endl;
	binTree->destroyTree();

	cin >> i;
	return 0;
}