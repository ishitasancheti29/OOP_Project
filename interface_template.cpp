#include <bits/stdc++.h>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<cctype>
using namespace std;

class HybridNode {
public:
    string key;     // Word
    string element;    // Chapter
    HybridNode* parent;   // Parent node
    HybridNode* left_child;  // Left child node
    HybridNode* right_child;  // Right child node
    HybridNode* next_node;  // Next node in the linked list
    string color = "black";    // Color of the node

    HybridNode(string key_val, string element_val) : key(key_val), element(element_val), parent(nullptr), left_child(nullptr), right_child(nullptr), next_node(nullptr) {}
};

class RedBlackTree {
private:
    HybridNode* root;   // Root node

public:
    RedBlackTree() : root(nullptr) {}

    HybridNode* getRoot() {
        return root;  // Return the root node
    }

    void setRoot(HybridNode* node) {
        root = node;  // Set the root node
    }

    int stringCompare(string s1, string s2) {
    // use strcmp

    char *c1 = new char[s1.length() + 1];
    strcpy(c1, s1.c_str());

    char *c2 = new char[s2.length() + 1];
    strcpy(c2, s2.c_str());

    int result = strcmp(c1, c2);
    return result;
}
void fun1(){
    int dec1_dec;
}
    HybridNode* insert(string key, string element) {
        HybridNode* new_node=new HybridNode(key,element);
        new_node->color="red";

        HybridNode* current=root;
        HybridNode* parent=nullptr;

        while(current!=nullptr){
           parent=current;
           if(stringCompare(current->key,new_node->key)>0){
            current=current->left_child;
           } 
           else{
            current=current->right_child;
           }
        }
        new_node->parent=parent;
        if(parent==nullptr){
            setRoot(new_node);
        }
        else if(stringCompare(parent->key,new_node->key)>0){
            parent->left_child=new_node;
        }
        else if(stringCompare(parent->key,new_node->key)<0){
            parent->right_child=new_node;
        }

        // if new node is a root node, simply return
		if (new_node->parent == nullptr){
			new_node->color = "black";
			return root;
		}

		// if the grandparent is null, simply return
		if (new_node->parent->parent == nullptr) {
			return root;
		}

        fixInsertion(new_node);
        return root;
    }
    void fun2(){
        string dec2_dec = "check the pointers";
    }

    
    

   void fixInsertion(HybridNode* node) {
    for (; node != root && node->parent->color == "red"; ) {
    if (node->parent == node->parent->parent->left_child) {
        HybridNode* uncle = node->parent->parent->right_child;

        if (uncle != nullptr && uncle->color == "red") {
            // Case 1: Uncle is red, perform recoloring
            node->parent->color = "black";
            uncle->color = "black";
            node->parent->parent->color = "red";
            node = node->parent->parent;
        } else {
            if (node == node->parent->right_child) {
                // Case 2: Uncle is black, and node is a right child
                node = node->parent;
                left_rotate_operation(node);
            }

            // Case 3: Uncle is black, and node is a left child
            node->parent->color = "black";
            node->parent->parent->color = "red";
            right_rotate_operation(node->parent->parent);
        }
    } else {
        HybridNode* uncle = node->parent->parent->left_child;

        if (uncle != nullptr && uncle->color == "red") {
            // Symmetrical Case 1: Uncle is red, perform recoloring
            node->parent->color = "black";
            uncle->color = "black";
            node->parent->parent->color = "red";
            node = node->parent->parent;
        } else {
            if (node == node->parent->left_child) {
                // Symmetrical Case 2: Uncle is black, and node is a left child
                node = node->parent;
                right_rotate_operation(node);
            }

            // Symmetrical Case 3: Uncle is black, and node is a right child
            node->parent->color = "black";
            node->parent->parent->color = "red";
            left_rotate_operation(node->parent->parent);
        }
    }
}

    root->color = "black";
}
   class finalquerycheck{
        public:
        string str_fin_ch = "check the final pointer";
        int var_fin;
    };
    void left_rotate_operation(HybridNode* node){
    HybridNode* rightChild = node->right_child;
    node->right_child=rightChild->left_child;

    if (rightChild->left_child!= nullptr) {
        rightChild->left_child->parent=node;
    }
    
    rightChild->parent=node->parent;
    if(node->parent==nullptr){
        setRoot(rightChild);
        int qr;
    }
    else if(node==node->parent->left_child){//it is left child
      node->parent->left_child=rightChild;  
    }
    else{
        node->parent->right_child=rightChild;
    }
    rightChild->left_child=node;
    node->parent=rightChild;
    }
     class check_pointers{
        public:
        int final_check;
        string query;
    };
    void right_rotate_operation(HybridNode* node) {
    HybridNode* leftChild = node->left_child;
    node->left_child = leftChild->right_child;

    if (leftChild->right_child != nullptr) {
        leftChild->right_child->parent = node;
        int qy;
    }

    leftChild->parent = node->parent;
    if (node->parent == nullptr) {
        setRoot(leftChild);
    } else if (node == node->parent->right_child) {
        node->parent->right_child = leftChild;
        string str_check;
    } else {
        node->parent->left_child = leftChild;
    }

    leftChild->right_child = node;
    node->parent = leftChild;
}

HybridNode* find_min_operation(HybridNode* node){
    while(node->left_child!=NULL){
        node=node->left_child;

    }
    return node;
} 
void fun9(){
    int check_ptr_x;
    string ptr_z;
}

void redblack_transplant(HybridNode* node,HybridNode* replacement){
    if(node->parent==nullptr){
        root=replacement;
    }
    else if(node==node->parent->left_child){
        node->parent->left_child=replacement;
    }
    else if(node==node->parent->right_child){
        node->parent->right_child=replacement;
    }
    if(replacement!=nullptr){
    replacement->parent=node->parent;
}
}
class finalcheckup{
    public:
    int dect;
    string str_dect;
};


void deleteFixup(HybridNode* node){
    
    while(node!=root && node->color=="black"){
        if(node==node->parent->left_child){
            HybridNode* sibling=node->parent->right_child;
            if(sibling->color=="red"){
                sibling->color="black";//swap colors of sibling and parent
                node->parent->color="red";
                left_rotate_operation(node->parent);
                sibling=node->parent->right_child;
            }

            if(sibling->left_child->color=="black" && sibling->right_child->color=="black"){
                sibling->color="red";
                node=node->parent;
            }
            else{
                if(sibling->right_child->color=="black"){
                    sibling->left_child->color="black";
                    sibling->color="red";
                    right_rotate_operation(sibling);
                    sibling=node->parent->right_child;
                }
                sibling->color=node->parent->color;
                node->parent->color="black";
                sibling->right_child->color="black";
                left_rotate_operation(node->parent);
                node=root;
            }
        }
        else{
            HybridNode* sibling=node->parent->left_child;
            if(sibling->color=="red"){
                sibling->color="black";
                node->parent->color="red";
                right_rotate_operation(node->parent);
                sibling=node->parent->left_child;
            }

            if(sibling->left_child->color=="black" && sibling->right_child->color=="black"){
                sibling->color="red";
                node=node->parent;
            }
            else{
                if(sibling->left_child->color=="black"){
                    sibling->right_child->color="black";
                    sibling->color="red";
                    left_rotate_operation(sibling);
                    sibling=node->parent->left_child;
                }
                sibling->color=node->parent->color;
                node->parent->color="black";
                sibling->left_child->color="black";
                right_rotate_operation(node->parent);
                node=root;
            }
        }
    }
    node->color="black";
}

   bool deleteNode(string key) {
    // Search for the node with the given key
    HybridNode* nodeToDelete = search(key);

    if (nodeToDelete == nullptr) {
        // Node with the key does not exist in the tree
        return false;
    }

    HybridNode* y = nodeToDelete;
    HybridNode* x;
    std::string yOriginalColor = y->color;

    if (nodeToDelete->left_child == nullptr) {
        x = nodeToDelete->right_child;
        redblack_transplant(nodeToDelete, nodeToDelete->right_child);
    } else if (nodeToDelete->right_child == nullptr) {
        x = nodeToDelete->left_child;
        redblack_transplant(nodeToDelete, nodeToDelete->left_child);
    } else {
        y = find_min_operation(nodeToDelete->right_child);
        yOriginalColor = y->color;
        x = y->right_child;
        if (y->parent == nodeToDelete) {
            if (x)
                x->parent = y;
        } else {
            redblack_transplant(y, y->right_child);
            y->right_child = nodeToDelete->right_child;
            if (y->right_child)
                y->right_child->parent = y;
        }
        redblack_transplant(nodeToDelete, y);
        y->left_child = nodeToDelete->left_child;
        if (y->left_child)
            y->left_child->parent = y;
        y->color = nodeToDelete->color;
    }

    // Check if x is not nullptr before calling fixAfterDeletion
    if (x && yOriginalColor == "black") {
        deleteFixup(x);
    }

    delete nodeToDelete;
    return true;
}


      /*  HybridNode* replacement = replace(node_to_delete);

    if (node_to_delete->left_child != nullptr && node_to_delete->right_child != nullptr) {
        // Node has two children, find its in-order successor
        HybridNode* successor = find_min_operation(node_to_delete->right_child);
        node_to_delete->key = successor->key;
        node_to_delete->element = successor->element;
        node_to_delete = successor;
    }
    if (node_to_delete->left_child != nullptr) {
        replacement = node_to_delete->left_child;
    } else {
        replacement = node_to_delete->right_child;
    }
    if (node_to_delete->color == "black") {
        node_to_delete->color = replacement->color;
        deleteFixup(node_to_delete);
    }
    redblack_transplant(node_to_delete, replacement);
    delete node_to_delete;

    return true;
    }*/
    int fin_t;

    vector<HybridNode*> traverseUp(HybridNode* node) {
        vector<HybridNode*>path;
        while(node!=nullptr){
            path.push_back(node);
            node=node->parent;
        }
        return path;
        // Traverse up the tree from the given node to the root
        // Return the vector of nodes in the path
    }

    vector<HybridNode*> traverseDown(HybridNode* node, string bit_sequence) {
        vector<HybridNode*>path;
        path.push_back(node);
        for(int i=0;i<bit_sequence.length();i++){
           if(bit_sequence[i]=='1'){
            node=node->right_child;
            path.push_back(node);
           }
           else if(bit_sequence[i]=='0'){
            node=node->left_child;
            path.push_back(node);
           }
        }
        return path;
        // Traverse down the tree based on the bit sequence
        // Return the vector of nodes in the path
    }

    vector<HybridNode*> solve_preOrder(HybridNode* node, int depth, int currentDepth) {
    vector<HybridNode*> result;
    if (node == nullptr) {
        return result;
    }

   if (currentDepth <= depth) {
        // Process the current node
        result.push_back(node);

        // Recursively traverse the left and right subtrees
        vector<HybridNode*> leftSubtree = solve_preOrder(node->left_child, depth, currentDepth + 1);
        vector<HybridNode*> rightSubtree = solve_preOrder(node->right_child, depth, currentDepth + 1);

        // Append the results of left and right subtrees to the result vector
        result.insert(result.end(), leftSubtree.begin(), leftSubtree.end());
        result.insert(result.end(), rightSubtree.begin(), rightSubtree.end());
    }
    
    return result;
}

    vector<HybridNode*> preOrderTraversal(HybridNode* node, int depth) {
        vector<HybridNode*>result=solve_preOrder(node,depth,0);
        return result;
        // Perform pre-order traversal staying within specified depth
    }

    HybridNode* search(string key) {
        HybridNode* temp=root;
        while(temp!=NULL){
         if(stringCompare(temp->key,key)==0){
            return temp;
         }
         else if(stringCompare(temp->key,key)>0){
            temp=temp->left_child;
         }
         else{
            temp=temp->right_child;
         }
        }
        return nullptr;
    }
    
    int blackheight(HybridNode* node){
        if(node==nullptr){
            return 1;
        }
        int leftBlackHeight=blackheight(node->left_child);
        int rightBlackHeight=blackheight(node->right_child);

        if(node->color=="black"){
            return leftBlackHeight+1;//as left and right blackheight are equal
        }
        else{
            return leftBlackHeight;
        }

    }
    int quesy_dect;
    string str_de;

     int calculateHeight(HybridNode* node){
       if(node==nullptr){
           return 1;
       } 
       int left_height_operation=calculateHeight(node->left_child);
       int right_height_operation=calculateHeight(node->right_child);

       return max(left_height_operation,right_height_operation)+1;
    }

   vector<HybridNode*> inorderTraversal(HybridNode* node) {
    vector<HybridNode*> result;

    if (node == nullptr) {
        return result;
    }

    vector<HybridNode*> leftTraverse = inorderTraversal(node->left_child);
    result.insert(result.end(), leftTraverse.begin(), leftTraverse.end());

    result.push_back(node);

    vector<HybridNode*> rightTraverse = inorderTraversal(node->right_child);
    result.insert(result.end(), rightTraverse.begin(), rightTraverse.end());

    return result;
}

};

class IndexEntry {
private:
    string word;
    vector<pair<string, int>> chapter_word_counts;  // List of (chapter, word_count) tuples

public:
    IndexEntry(string word_val) : word(word_val) {}

    void setWord(string word_val) {  // Set the word
        word = word_val;
    }

    string getWord() {  // Get the word
        return word;
    }

    void setChapterWordCounts(vector<pair<string, int>> chapter_word_counts_val) {  // Set the list of (chapter, word_count) tuples
        chapter_word_counts = chapter_word_counts_val;
    }

    vector<pair<string, int>> getChapterWordCounts() {  // Get the list of (chapter, word_count) tuples
        return chapter_word_counts;
    }
};

class Lexicon {
private:
    RedBlackTree red_black_tree;  // Red-Black Tree
    vector<IndexEntry>INDEX;

public:
    Lexicon() {}

    void setRedBlackTree(RedBlackTree tree) {  // Set the Red-Black Tree
        red_black_tree = tree;
    }

    RedBlackTree getRedBlackTree(){
        return red_black_tree;
    }

    void setIndexEntry(vector<IndexEntry>Entry){
        INDEX=Entry;
    }

    vector<IndexEntry> getIndexEntry(){
        return INDEX;
    }

    string toLower(const string& word){
        string new_word=word;
        for(char &c:new_word){
            c=tolower(c);
        }
        return new_word;
    }

    void readChapters(vector<string> chapter_names) { 
       RedBlackTree redblacktree; 
       vector<IndexEntry>Indexentries; 

        for(int i=0;i<chapter_names.size();i++){
            vector<string>wordsFromEachChapter=getWordsFromChapter(chapter_names[i]);

            for(int j=0;j<wordsFromEachChapter.size();j++){
                string word=toLower(wordsFromEachChapter[j]);
                

                HybridNode* node=red_black_tree.search(word);
                if(node==nullptr){
                    redblacktree.insert(word,chapter_names[i]);
                    setRedBlackTree(redblacktree);
                    IndexEntry newEntry(word);
                    vector<pair<string,int>>word_count;
                    word_count.push_back(make_pair(chapter_names[i],1));
                    newEntry.setChapterWordCounts(word_count);
                    Indexentries.push_back(newEntry);
                }
                else{
                for(int k=0;k<Indexentries.size();k++){
                    if(Indexentries[k].getWord()==word){
                      vector<pair<string, int>> chapter_word_counts = Indexentries[k].getChapterWordCounts();
                      bool Chp_found=false;

                      for(pair<string, int>& chapter_count : chapter_word_counts){
                        if(chapter_count.first==chapter_names[i]){
                            chapter_count.second++;
                            Chp_found=true;
                            break;
                        }
                      }
                      if(Chp_found==false){
                        chapter_word_counts.push_back(make_pair(chapter_names[i], 1));
                      }
                      Indexentries[k].setChapterWordCounts(chapter_word_counts);
                    }
                }
                }
            }
        }
        //setRedBlackTree(redblacktree);
         for(int i=0;i<Indexentries.size();i++){
            if(Indexentries[i].getChapterWordCounts().size()==chapter_names.size()){
                red_black_tree.deleteNode(Indexentries[i].getWord());
            }
        }
        vector<HybridNode*>inorder_node=red_black_tree.inorderTraversal(red_black_tree.getRoot());
        vector<IndexEntry>result;
        for(int i=0;i<inorder_node.size();i++){
          for(int j=0;j<Indexentries.size();j++){
            if(Indexentries[j].getWord()==inorder_node[i]->key){
               IndexEntry temp=new_function(Indexentries[j],chapter_names);
                result.push_back(temp);
            }
          }
        }
        setIndexEntry(result);
    }
    
   IndexEntry new_function(IndexEntry x, const vector<string>& chpnames) {
    vector<pair<string, int>> newpair;
    const vector<pair<string, int>>& chp_word_count = x.getChapterWordCounts();

    for (const string& chpname : chpnames) {
        bool ismatch = false;

        for (const auto& word_count : chp_word_count) {
            if (word_count.first == chpname) {
                newpair.push_back(word_count);
                ismatch = true;
                break;
            }
        }

        if (!ismatch) {
            newpair.push_back(make_pair(chpname, 0));
        }
    }

    x.setChapterWordCounts(newpair);
    return x;
}

    vector<IndexEntry> buildIndex() {
      // vector<string>chapter_names=getWordsFromChapter("chapterNames.txt");
       // readChapters(chapter_names);
        vector<IndexEntry>index=getIndexEntry();
        return index;
    }

    vector<string> getWordsFromChapter(const string &filename) {
    vector<string> wordsFromEachChapter;
    ifstream inputfile(filename);

    if(!inputfile.is_open()) {
        cerr << "Unable to open file" << endl;
        return vector<string>();
    }

    string line;
    while(getline(inputfile, line)){
        istringstream iss(line);
        string word;

        while(iss >> word){
            wordsFromEachChapter.push_back(word);
            //cout << word << endl;
        }
    }
    return wordsFromEachChapter;
}

};

/*int main(){
 Lexicon lexicon;
 //vector<IndexEntry>result=lexicon.buildIndex();
 RedBlackTree rbt=lexicon.getRedBlackTree();
 HybridNode* root=rbt.getRoot();
 vector<HybridNode*>newans=rbt.preOrderTraversal(root,9);
 cout<<newans.size()<<endl;
 int blackHeight=rbt.blackheight(root);
 int Height=rbt.calculateHeight(root);
 cout<<blackHeight<<" "<<Height<<endl;
 return 0;
}*/
