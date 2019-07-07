"""
Binary tree class
Provides minimum neccessory interface to build and print tree
"""

import queue

class Node(object):
    """Represents a binary tree node."""

    def __init__(self, key):
        self.left = None
        self.right = None
        self.data = key

class BinaryTree(object):
    def __init__(self, root=None):
        self.root = root

    def get_root(self):
        return self.root

    @classmethod
    def from_list(cls, keys):
        """Decorator to build class from list of keys"""
        bt = cls()

        for i in keys:
            bt.level_order_insert(i);
        return bt

    def build_from_list(self, keys):
        """Construct BT from given list of keys.
        Level order insertion is followed
        """

        for i in keys:
            self.level_order_insert(i);


    def btToBST(self):
        from bt_utils import BTUtils

        if self.root is None:
            return

        inorder = list()
        BTUtils.inorderList(self.root, inorder)
        inorder.sort()

        BTUtils.listToBST(inorder, self.root, [0])

    def level_order_insert(self, key):
        """ Insert key in level order
        :param key: Key to insert in level order
        """

        if self.root is None:
            self.root = Node(key)
            return

        q = queue.Queue()
        q.put(self.root)
        while q.qsize()>0:
            e = q.get()
            if e.left == None:
                e.left = Node(key)
                break
            else:
                q.put(e.left)
            if e.right == None:
                e.right = Node(key)
                break
            else:
                q.put(e.right)

    def is_bst(self, root):
        """Return True if BT is BST False otherwise """

        if root is None:
            return True

        if root.left is not None and root.data < root.left.data:
            return False
        else:
            return self.is_bst(root.left)

        if root.right is not None and root.data > root.right.data:
            return False
        else:
            return self.is_bst(root.right)

    def build_tree_string(self, root):
        """Recursively walk down the binary tree and build a pretty-print string."""

        if root is None:
            return [], 0, 0, 0

        line1 = []
        line2 = []
        node_repr = str(root.data)

        new_root_width = gap_size = len(node_repr)

        # Get the left and right sub-boxes, their widths, and root repr positions
        l_box, l_box_width, l_root_start, l_root_end = \
        self.build_tree_string(root.left)
        r_box, r_box_width, r_root_start, r_root_end = \
        self.build_tree_string(root.right)

        # Draw the branch connecting the current root node to the left sub-box
        # Pad the line with whitespaces where necessary
        if l_box_width > 0:
            l_root = (l_root_start + l_root_end) // 2 + 1
            line1.append(' ' * (l_root + 1))
            line1.append('_' * (l_box_width - l_root))
            line2.append(' ' * l_root + '/')
            line2.append(' ' * (l_box_width - l_root))
            new_root_start = l_box_width + 1
            gap_size += 1
        else:
            new_root_start = 0

        # Draw the representation of the current root node
        line1.append(node_repr)
        line2.append(' ' * new_root_width)

        # Draw the branch connecting the current root node to the right sub-box
        # Pad the line with whitespaces where necessary
        if r_box_width > 0:
            r_root = (r_root_start + r_root_end) // 2
            line1.append('_' * r_root)
            line1.append(' ' * (r_box_width - r_root + 1))
            line2.append(' ' * r_root + '\\')
            line2.append(' ' * (r_box_width - r_root))
            gap_size += 1
        new_root_end = new_root_start + new_root_width - 1

        # Combine the left and right sub-boxes with the branches drawn above
        gap = ' ' * gap_size
        new_box = [''.join(line1), ''.join(line2)]
        for i in range(max(len(l_box), len(r_box))):
            l_line = l_box[i] if i < len(l_box) else ' ' * l_box_width
            r_line = r_box[i] if i < len(r_box) else ' ' * r_box_width
            new_box.append(l_line + gap + r_line)

        # Return the new box, its width and its root repr positions
        return new_box, len(new_box[0]), new_root_start, new_root_end


    def pprint(self):
        """Pretty-print the binary tree."""

        lines = self.build_tree_string(self.root)[0]
        print('\n' + '\n'.join((line.rstrip() for line in lines)))

if __name__ == "__main__":
    bt = BinaryTree.from_list( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15])
    bt.btToBST()
    bt.pprint()


