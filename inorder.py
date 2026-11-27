class node:
    def __init__ (self, data):
        self.data = data
        self.left = None
        self.right = None
        
root=node(50)
root.left=node(40)
root.right=node(60)
root.left.left=node(30)
root.left.right=node(45)
root.right.left=node(55)
root.right.right=node(70)

def inorder(root):
    if root is not None:
        
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)
        
        
print("inorder traversal:")
inorder(root)
