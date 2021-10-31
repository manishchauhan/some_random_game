//implement a binary search tree in js -------------------------------------
class TreeNode
{
    data:any
    left:TreeNode
    right:TreeNode
    constructor(__data:any)
    {
      this.data=__data;
    }
}
class Tree
{

  //add a node to the tree
  root:TreeNode=null
   
  //public----------------------------------------------------
  public insert(data:any)
  {
     if(this.root!=null)
     {
       this.insertWithLeaf(data,this.root)
     }else
     {
        this.root=new TreeNode(data);
        this.root.left=null;
        this.root.right=null;
     }
        
  }
 //insert value in a tree----------------------------------------------
 







  //private----------------------------------------------------
   insertWithLeaf(data:any,leaf:TreeNode)
  {
      //add node to left
      if(data<leaf.data)
      {
         if(leaf.left!=null)
         {
            this.insertWithLeaf(data,leaf.left);
         }else
         {
            leaf.left=new TreeNode(data);
            leaf.left.left=null;
            leaf.left.right=null;
         }
      }
      //add node to right
      else if(data>leaf.data)
      {
         if(leaf.right!=null)
         {
            this.insertWithLeaf(data,leaf.right);
         }else
         {

            leaf.right=new TreeNode(data);
            leaf.right.left=null;
            leaf.right.right=null;
         }
      }
  }
  //print data inorder-------------------------------------------left root right
  printInOrder()
  {
     this.displayInOrder(this.root);
  }
  displayInOrder(leaf)
  {
    if(leaf!=null)
    {
      
       this.displayInOrder(leaf.left);
       console.log(leaf.data);
       this.displayInOrder(leaf.right);
    }
  }
  //print preorder-----------root left right-----------------------------------
   printPreOrder()
  {
     this.displayPreOrder(this.root);
  }
   displayPreOrder(leaf)
  {
    if(leaf!=null)
    {
       console.log(leaf.data);
       this.displayPreOrder(leaf.left);
       this.displayPreOrder(leaf.right);
    }
  }
  //height of tree
  getHeight(node)
  {

     if(node==null)
     {
        return -1;
     }
     else 
     {
      
        return 1+Math.max(this.getHeight(node.left),this.getHeight(node.right));
     }
  }
 getDepth(node)
  {

     if(node==null)
     {
        return -1;
     }
     else 
     {
      
        return 1+Math.max(this.getDepth(node.left),this.getDepth(node.right));
     }
  }
   
  //print preorder-----------left right root-----------------------------------
   printPostOrder()
  {
    
     this.displayPostOrder(this.root);
  }
   displayPostOrder(leaf)
  {
    if(leaf!=null)
    {
      
       this.displayPostOrder(leaf.left);
       this.displayPostOrder(leaf.right);
        console.log(leaf.data);
    }
  }
  //search in tree------------------------------divide into two parts

  SearchInTree(node,data)
  {
    let currentNode=node;
    while(currentNode!=null)
    {
        if(currentNode.data==data)
        {
   
         return currentNode;    
        }
        if(currentNode.data>data)
         {
           currentNode=currentNode.left;
          }
        else if(currentNode.data<data)
        {
           currentNode=currentNode.right;
        }
    }
  
  }
}

var binarySearchTree=new Tree();
binarySearchTree.insert("manish");
binarySearchTree.insert("sachin");
binarySearchTree.insert("seema");
binarySearchTree.insert("nitin");
binarySearchTree.insert("deepak");
binarySearchTree.insert("sanjay");
binarySearchTree.printPostOrder();
console.log(binarySearchTree.getHeight(binarySearchTree.root));
console.log(binarySearchTree.getDepth(binarySearchTree.root));
//console.log(binarySearchTree.Search(120));
/*
console.log("INORDER--------------------->>")
binarySearchTree.printInOrder();
console.log("PREORDER--------------------->>")
binarySearchTree.printPreOrder();

console.log("POSTORDER--------------------->>")

*/
//console.log(binarySearchTree.SearchInTree(binarySearchTree.root,"manish"));