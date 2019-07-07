"""
Various tree traversal algorithms are implemented in this module
"""

from binary_tree import Node, BinaryTree
import queue

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

class BFSTraversal(object):
    def __init__(self):
        pass

    @staticmethod
    def levelorder(root):
        """print level order nodes from left to right"""
        q = queue.Queue(0)
        q.put(root)
        while q.qsize()>0:
            e = q.get()
            print(e.data, end='  ')
            if e.left != None:
                q.put(e.left)
            if e.right != None:
                q.put(e.right)

    @staticmethod
    def spiralorder(root):
        """Prints tree in spiral order, left to right -> right to left->left to right .. in a level
        *Algorithm
        -Use two stacks s1 and s2
        -insert root into s1, ltr flag = True
        -Repeat until s1 or s2 is not empty
        -     if s1 is not empty and ltr = True, pop from s1 and print, insert into s2
        -    if s2 is not empty and ltr = False, pop from s2 and print, insert into s1
        -    toggle ltr on transition
        """
        if root == None:
            return
        s1 = list() #for left to right
        s2 = list() #for right to left
        s1.append(root)
        ltr = True
        while len(s1)>0 or len(s2)>0:
            if len(s1)>0 and ltr== True:
                cur =  s1.pop()
                print(cur.data, end ='  ')
                if cur.right != None:
                    s2.append(cur.right)
                if cur.left != None:
                    s2.append(cur.left)
            if len(s2)>0 and ltr == False:
                cur = s2.pop()
                print(cur.data, end='  ')
                if cur.left != None:
                    s1.append(cur.left)
                if cur.right != None:
                    s1.append(cur.right)
            if len(s1) == 0:
                ltr = False
            if len(s2) == 0:
                ltr = True

class BoundaryTraversal(object):
    """ Prints the boundary nodes of BT"""
    def __init__(self):
        pass

    @staticmethod
    def __left_boundary_util(root):
        """This method is customized boundary traversal, does not print leftmost node
        print left boundary top to bottom
        """
        if root is None:
            return

        if root.left is not None:
            print(root.data, end='  ')
            BoundaryTraversal.__left_boundary_util(root.left)
        elif root.right is not None:
            print(root.data, end=' ')
            BoundaryTraversal.__left_boundary_util(root.right)

    @staticmethod
    def __right_boundary_util(root):
        """This method is customized for boundary traversal, does not print rightmost node
        print right boundary bottom up
        """

        if root is None:
            return

        if root.right:
            BoundaryTraversal.__right_boundary_util(root.right)
            print(root.data, end='  ')

        elif root.left:
            BoundaryTraversal.__right_boundary_util(root.left)
            print(root.data, end='  ')

    @staticmethod
    def leaves(root):
        """Prints leaf node from left to right"""
        if root is None:
            return

        BoundaryTraversal.leaves(root.left)
        if root.left is None and root.right is None:
            print(root.data, end='  ')
        BoundaryTraversal.leaves(root.right)


    @staticmethod
    def anti_clockwise(root):
        """
         *Algoriym
         1. Print the left boundary in top-down manner.
         2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
         3. Print the right boundary in bottom-up manner.

        :param root:
        :return:
        """
        if root is None:
            return

        print(root.data, end='  ')
        BoundaryTraversal.__left_boundary_util(root.left)
        BoundaryTraversal.leaves(root)
        BoundaryTraversal.__right_boundary_util(root.right)


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
    print("MorrisTraversal Methods")
    print("     Inorder traversal - ",  end=' ')
    MorrisTraversal.inorder(bt.get_root())
    print()
    print("     Preorder traversal - ",  end=' ')
    MorrisTraversal.preorder(bt.get_root())
    print()
    print()
    print('BFS Traversal Methods - ')
    print("     Level order traversal - ",  end=' ')
    BFSTraversal.levelorder(bt.get_root())
    print()
    print('     Spiral order - ', end=' ')
    BFSTraversal.spiralorder(bt.get_root())
    print()
    print()
    print('Boundary traversal Methods - ')
    print('     Anticlockwise boundary - ', end='  ')
    BoundaryTraversal.anti_clockwise(bt.get_root())







