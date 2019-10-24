"""
Implements commonly utility functions of BT
"""
from binary_tree import BinaryTree, Node

class BTUtils(object):
    def __init__(self):
        pass

    @staticmethod
    def LCA(root, key1, key2):
        """ Returns node which parent of both left and right s"""
        if root == None:
            return None
        if root.data == key1 or root.data == key2:
            return root
        left = BTUtils.LCA(root.left, key1, key2)
        right = BTUtils.LCA(root.right, key1, key2)

        if left != None and right != None:
            return root
        if left == None and right == None:
            return None
        if left!=None:
            return left
        return right

    @staticmethod
    def height(root):
        """return height of BT from given root."""

        if root is None:
            return 0

        return 1 + max(BTUtils.height(root.left), BTUtils.height(root.right))

    def __level_util(root, key, lvl):
        if root == None:
            return -1
        if root.data == key:
            return lvl

        height = BTUtils.__level_util(root.left, key, lvl+1)
        if height == -1:
            return BTUtils.__level_util(root.right, key, lvl+1)
        return height

    @staticmethod
    def level(root, key):
        """Compute the level/height of node(key) relative to root node
        *Assumptions - root level is based to 1
        """
        return BTUtils.__level_util(root, key, 1)

    @staticmethod
    def countNodes(root):
        if root is None:
            return 0

        return BTUtils.countNodes(root.left) + BTUtils.countNodes(root.right) + 1

    @staticmethod
    def inorderList(root, inorder):
        if root is None:
            return

        BTUtils.inorderList(root.left, inorder)
        inorder.append(root.data)
        BTUtils.inorderList(root.right, inorder)

    @staticmethod
    def listToBST(inorder, root, index):
        if root is None:
            return

        BTUtils.listToBST(inorder, root.left, index)
        root.data = inorder[index[0]]
        index[0] += 1
        BTUtils.listToBST(inorder, root.right, index)


if __name__ == '__main__':
    bt = BinaryTree.from_list( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15])
    bt.pprint()
    print('Height of binary tree - ', end='  ')
    print(BTUtils.height(bt.get_root()))
    print('Lowest Common Ancestor of 4 and 13 - ', end='  ')
    print(BTUtils.LCA(bt.get_root(), 4, 13).data)
    print('Level of node 7 - ', end='  ')
    print(BTUtils.level(bt.get_root(), 7))
