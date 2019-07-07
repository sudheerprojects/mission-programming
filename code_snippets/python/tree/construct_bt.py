"""
Implementation of binary tree constructions from different traversals
"""

from binary_tree import BinaryTree, Node
from bt_utils import BTUtils

class BuildTree(object):
    def __init__(self):
        pass

    @staticmethod
    def from_in_pre(ino, pre, start, end, preidx):
        """ Construct tree from given inorder and preorder traversal arrays
        *Algorithm
        - First element of pre order traversal is root of the tree whose position in in-order traversal
        - divides into left sub-tree and right sub-tree.
        """
        if start>end:
            return None

        root = Node(pre[preidx[0]])
        preidx[0] = preidx[0] + 1
        if start == end:
            return root

        inidx = ino.index(root.data, start, end+1)

        root.left = BuildTree.from_in_pre(ino, pre, start, inidx-1, preidx)
        root.right = BuildTree.from_in_pre(ino, pre, inidx+1, end, preidx)

        return root


if __name__ == '__main__':
    ino = [4, 8, 2, 9, 5, 1, 6, 3, 7, 10]
    pre = [1, 2, 4, 8, 5, 9, 3, 6, 7, 10]
    root = BuildTree.from_in_pre(ino, pre, 0, len(pre)-1, [0])
    bt = BinaryTree(root)
    bt.pprint()

