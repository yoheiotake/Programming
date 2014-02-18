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
  void printInorder(  ){ printInorder( root ); }
  void printInorder( Node *r );
  void printPreorder(  ){ printPreorder( root ); }
  void printPreorder( Node *r );
  void printPostorder(  ){ printPostorder( root ); }
  void printPostorder( Node *r );
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

Node * BinaryTree::insertNode( Node *r, int d ) {
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

void BinaryTree::printInorder( Node *r ) {
  if(r == NULL)
    return;
  if(r -> left != NULL)
    printInorder(r -> left);
  cout << r -> data << ' ';
  if(r -> right != NULL)
    printInorder(r -> right);

  return;
}

void BinaryTree::printPreorder( Node *r ) {
  if(r == NULL)
    return;
  cout << r -> data << ' ';
  printPreorder(r -> left);
  printPreorder(r -> right);

  return;
}

void BinaryTree::printPostorder( Node *r ) {
  if(r == NULL)
    return;
  printPostorder(r -> left);
  printPostorder(r -> right);
  cout << r -> data << ' ';

  return;
}

Node * BinaryTree::removeAll( Node *r ) {
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
  int option;

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

  cout << "二分探索木のデータを表示します．\n1: インオーダー, 2: プリオーダー, 3: ポストオーダー >> ";
  cin >> option;
           
  if(option == 1) {
    bt1.printInorder( );
    cout << endl;
  }

  else if(option == 2) {
    bt1.printPreorder( );
    cout << endl;
  }

  else if(option == 3) {
    bt1.printPostorder( );
    cout << endl;
  }

  else {
    cout << "1～3　の数字を入力してください. " << endl;
  }

  return 0;
}
