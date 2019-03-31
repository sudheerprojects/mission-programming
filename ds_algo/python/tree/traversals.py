"""
Various tree traversal algorithms are implemented in this module
"""

from binary_tree import Node, BinaryTree

class RecursiveTraversal(object):
    """Implements tree traversal in recursive approach"""
    def __init__(self):
        pass

    @staticmethod
    def inorder(root):
        """Visit nodes from left, root, right
        Analysis
        -------------------
        *Time complexity O(n), each node is visited atleast once
        *Space complexity 0(1)
        Note: Stack frames are not considered for space complexity
        """
        if root is None:
            return

        RecursiveTraversal.inorder(root.left)
        print(root.data, end='  ')
        RecursiveTraversal.inorder(root.right)

    @staticmethod
    def preorder(root):
        """ Visit nodes from root, left, right
        Analysis
        -------------------
        *Time complexity O(n)
        *Space complexity 0(1)
        Note: Stack frames are not considered for space complexity
        """

        if root is None:
            return
        print(root.data, end='  ')
        RecursiveTraversal.preorder(root.left)
        RecursiveTraversal.preorder(root.right)

    @staticmethod
    def postorder(root):
        """ Visit nodes from left, root, right
        Analysis
        -------------------
        *Time complexity O(n)
        *Space complexity 0(1)
        Note: Stack frames are not considered for space complexity
        """

        if root is None:
            return
        RecursiveTraversal.postorder(root.left)
        RecursiveTraversal.postorder(root.right)
        print(root.data, end='  ')

class IterativeTraversal:
    """Implements tree traversal in iterative manner
    Stack is used for auxiliary storage"""
    def __init__(self):
        pass

    @staticmethod
    def inorder(root):
        """ Visit nodes from left, root, right
        Analysis
        -------------------
        *Time complexity O(n)
        *Space complexity 0(n)
         """
        stack = [];
        cur = root;
        while cur != None or len(stack)>0:
            #build the stack of left subtree
            if cur != None:
                stack.append(cur)
                cur = cur.left
                continue

        cur =stack.pop()
        print(cur.data)
        cur = cur.right

    @staticmethod
    def preorder(root):
        """ Visit nodes from root, left, right
        Analysis
        -------------------
        *Time complexity O(n)
        *Space complexity 0(n)
         """
        if root == None:
            return

        stack = [];
        stack.append(root)
        while len(stack)>0:
            cur = stack.pop()
            print(cur.data)
            if cur.right != None:
                stack.append(cur.right)
            if cur.left != None:
                stack.append(cur.left)

    @staticmethod
    def postorder(root):
        """ Visit nodes from left, right, root
        Analysis
        -------------------
        *Time complexity O(n)
        *Space complexity 0(n)
        """

        if root == None:
            return
        stack = []
        cur = root

        while True:
            while cur != None:
                if cur.right != None:
                    stack.append(cur.right)
                stack.append(cur)
                cur = cur.left

            cur = stack.pop()
            #If the top of the stack is same as immediate right then visit right subtree first
            if(len(stack)>0 and cur.right != None and stack[-1] == cur.right):
                stack.pop()
                stack.append(cur)
                cur = cur.right
            else:
                print(cur.data)
                cur = None

class MorrisTraversal:
    """Tree traversal without using recursion and stack/queue"""
    def __init__(self):
        pass

    @staticmethod
    def find_predecessor(cur):
        pred = cur.left
        while pred.right != cur and pred.right is not None:
            pred = pred.right
        return pred

    @staticmethod
    def inorder(root):
        """In this traversal create links to inorder successor"""
        cur = root
        while cur is not None:
            if cur.left is None:
                print(cur.data, end='  ')
                cur = cur.right
            else:
                # Find the inorder predecessor of current
                pred = MorrisTraversal.find_predecessor(cur)

                # Make current as right child of its inorder predecessor
                if pred.right is None:
                    pred.right = cur
                    cur = cur.left

                # Revert the changes made in if part to restore the
                # original tree i.e., fix the right child of predecessor
                else:
                    pred.right = None
                    print (cur.data, end='  ')
                    cur = cur.right

    @staticmethod
    def preorder(root):
        cur = root
        while cur is not None:
            if cur.left is None:
                print (cur.data, end='  ')
                cur = cur.right
            else:
                pred = MorrisTraversal.find_predecessor(cur)

                if pred.right is None:
                    print (cur.data, end='  ')
                    pred.right = cur
                    cur = cur.left
                else:
                    pred.right = None
                    cur = cur.right


if __name__ == "__main__":
    bt = BinaryTree.from_list( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15])
    bt.pprint()
    print("Recursive Traversal Methods")
    print("     Inorder traversal - ",  end=' ')
    RecursiveTraversal.inorder(bt.get_root())
    print()
    print("     Preorder traversal - ",  end=' ')
    RecursiveTraversal.preorder(bt.get_root())
    print()
    print("     Postorder traversal - ",  end=' ')
    RecursiveTraversal.postorder(bt.get_root())
    print()
    print()
    print("Iterative Traversal Methods Using Auxiliary Storage")
    print("     Inorder traversal - ",  end=' ')
    RecursiveTraversal.inorder(bt.get_root())
    print()
    print("     Preorder traversal - ",  end=' ')
    RecursiveTraversal.preorder(bt.get_root())
    print()
    print("     Postorder traversal - ",  end=' ')
    RecursiveTraversal.postorder(bt.get_root())
    print()
    print()
    print("MorrisTraversal Method")
    print("     Inorder traversal - ",  end=' ')
    MorrisTraversal.inorder(bt.get_root())
    print()
    print("     Preorder traversal - ",  end=' ')
    MorrisTraversal.preorder(bt.get_root())
    print()
    print()







