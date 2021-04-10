#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

Node *empty = NULL;

Node *node(int value, Node *left, Node *right) { 
  Node *r = malloc(sizeof(Node));
  r->marked = false;
  r->value = value;
  r->left = left;
  r->right = right;
  return r;
}


/* Basic Problems */

int size(Node *node) { 
  /* TODO */
  if (node==NULL) {
	  return 0;
  } else if (node->marked==true) {
	  return 0;
  }
  node->marked=true;
  return 1+size(node->left)+size(node->right);
}


void unmark(Node *node) { 
  /* TODO */
  if (node==NULL) {
	  return;
  } else if (node->marked==false) {
	  return;
  } else {
	  node->marked=false;
	  unmark(node->left);
	  unmark(node->right);
  }
}

bool path_from(Node *node1, Node *node2) {
  /* TODO */
  if (node1 == NULL || node2 == NULL) {
	  return false;
  }
  
  if (node1==node2) {
	  return true;
  } else {
	  return path_from(node1->left,node2) || path_from(node1->right,node2);
  }
}

bool cyclic(Node *node) { 
  /* TODO */
  //need this because we use ->left and ->right
  //could be null pointer exception
  if(node==NULL) {
	  return false;
  }
  //could do it this way
  //mark node and everything reachable from node
  //unmark anything reachable from any of nodes kids
  //if node is now unmarked we have a cycle to node
  
  //but can also just use path from node kids back to
  //node
  return path_from(node->left,node) || path_from(node->right,node);
} 


/* Challenge problems */

void get_nodes(Node *node, Node **dest) { 
  /* TODO */
  if (node==NULL) {
	  return;
  }
  if (node->marked==true) {
	  return;
  }
  node->marked=true;
  *dest = node;
  dest++;
  get_nodes(node->left,dest);
  get_nodes(node->right,dest);
}

void graph_free(Node *node) { 
  /* TODO */
  int n = size(node);
  Node *array[n];
  get_nodes(node,array);
  for (int i=0; i<n; i++) {
	  free(array+i);
  }
  
}


