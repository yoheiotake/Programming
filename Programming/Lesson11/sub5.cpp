#include <iostream>
using namespace std;

class Node {
  friend class BinaryTree;
private:
  int data;
  Node *left;
  Node *right;
public:
  Node( int _data );
};

class BinaryTree {
private:
  Node *root;
public:   
  BinaryTree( );
  ~BinaryTree( );
  void insertNode( int d ) { root = insertNode( root, d ); }
  Node *insertNode( Node *r, int d );
  bool search( int key );
  Node *removeAll( Node *r );
};

Node::Node( int _data ) {
  data = _data; 
  left = NULL;
  right = NULL;
}

BinaryTree::BinaryTree( ) {
  root = NULL; 
};

BinaryTree::~BinaryTree( ) {
  root = removeAll( root );
};

Node* BinaryTree::insertNode( Node *r, int d ) {
  if(r == NULL){
    r = new Node(d);
    return r;
  }
  if(r -> data <= d)
    r -> right = insertNode(r -> right, d);
  else
    r -> left = insertNode(r -> left, d);

  return r;
}

bool BinaryTree::search( int key ) {

  Node *p = root;

  while(p != NULL){
    if(p -> data == key)
      return true;
    else if(p -> data > key)
      p = p -> left;
    else
      p = p -> right;
  }
  return false;
}

Node* BinaryTree::removeAll( Node *r ) {
  if(r == NULL)
    return NULL;

  r -> left = removeAll(r -> left);
  r -> right = removeAll(r -> right);

  cout << r -> data <<" を削除しました．"<< endl;
  delete r;
  return NULL;
}

int main(  ) {
  BinaryTree bt1;
  int key;
    
  bt1.insertNode( 9 );
  bt1.insertNode( 3 );
  bt1.insertNode( 6 );
  bt1.insertNode( 2 );
  bt1.insertNode( 5 );
  bt1.insertNode( 1 );
  bt1.insertNode( 7 );
  bt1.insertNode( 55 );
  bt1.insertNode( 63 );
  bt1.insertNode( 24 );

  cout << "二分探索木のデータを探索します．\n探索キー >> ";
  cin >> key;
    
  bool result = bt1.search( key );
    
  if(result == true) {
    cout << "データ " << key << " が見つかりました. " << endl;
  }
  else {
    cout << "データ " << key << " は見つかりませんでした. " << endl;
  }

  return 0;
}
