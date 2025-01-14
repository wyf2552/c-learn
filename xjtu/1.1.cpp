#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

// 二叉树节点结构
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    // 添加线索二叉树需要的标记
    bool leftThread;
    bool rightThread;
    TreeNode(char x) : data(x), left(nullptr), right(nullptr),
                       leftThread(false), rightThread(false) {}
};

class BinaryTree {
private:
    TreeNode* root;
    TreeNode* pre; // 用于线索化

    // 创建二叉树的辅助函数
    TreeNode* createTree() {
        char ch;
        cin >> ch;
        if (ch == '#') return nullptr;

        TreeNode* node = new TreeNode(ch);
        node->left = createTree();
        node->right = createTree();
        return node;
    }

    // 销毁树的辅助函数
    void destroyTree(TreeNode* node) {
        if (!node) return;
        if (!node->leftThread) destroyTree(node->left);
        if (!node->rightThread) destroyTree(node->right);
        delete node;
    }

    // 中序遍历进行线索化的辅助函数
    void inThreading(TreeNode* curr) {
        if (!curr) return;

        inThreading(curr->left);

        if (!curr->left) {
            curr->leftThread = true;
            curr->left = pre;
        }
        if (pre && !pre->right) {
            pre->rightThread = true;
            pre->right = curr;
        }
        pre = curr;

        inThreading(curr->right);
    }

public:
    BinaryTree() : root(nullptr), pre(nullptr) {}
    ~BinaryTree() {
        destroyTree(root);
    }

    // 1. 创建二叉树
    void createBinaryTree() {
        cout << "请输入二叉树节点（#表示空节点）:";
        root = createTree();
    }

    // 前序遍历
    void preOrder(TreeNode* node) {
        if (!node) return;
        cout << node->data << " ";
        if (!node->leftThread) preOrder(node->left);
        if (!node->rightThread) preOrder(node->right);
    }

    // 中序遍历
    void inOrder(TreeNode* node) {
        if (!node) return;
        if (!node->leftThread) inOrder(node->left);
        cout << node->data << " ";
        if (!node->rightThread) inOrder(node->right);
    }

    // 后序遍历
    void postOrder(TreeNode* node) {
        if (!node) return;
        if (!node->leftThread) postOrder(node->left);
        if (!node->rightThread) postOrder(node->right);
        cout << node->data << " ";
    }

    // 1. 输出三种遍历
    void printAllTraversals() {
        cout << "\n前序遍历:";
        preOrder(root);
        cout << "\n中序遍历:";
        inOrder(root);
        cout << "\n后序遍历:";
        postOrder(root);
        cout << endl;
    }

    // 2. 计算叶子节点数
    int countLeaf(TreeNode* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        return countLeaf(node->left) + countLeaf(node->right);
    }

    int getLeafCount() {
        return countLeaf(root);
    }

    // 3. 计算树的高度
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    int getTreeHeight() {
        return getHeight(root);
    }

    // 4. 交换左右子树并输出前序和中序遍历
    void swapSubtrees(TreeNode* node) {
        if (!node) return;
        // 交换当前节点的左右子树
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        // 递归交换子树
        if (!node->leftThread) swapSubtrees(node->left);
        if (!node->rightThread) swapSubtrees(node->right);
    }

    void swapAndPrint() {
        swapSubtrees(root);
        cout << "\n交换后的前序遍历:";
        preOrder(root);
        cout << "\n交换后的中序遍历:";
        inOrder(root);
        cout << endl;
    }

    // 5. 非递归后序遍历
    void nonRecursivePostOrder() {
        cout << "\n非递归后序遍历:";
        if (!root) return;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);

            if (!node->leftThread && node->left)
                s1.push(node->left);
            if (!node->rightThread && node->right)
                s1.push(node->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
        cout << endl;
    }

    // 6. 中序线索化
    void createInorderThread() {
        if (!root) return;
        pre = nullptr;
        inThreading(root);
        if (pre) {
            pre->rightThread = true;
            pre->right = nullptr;
        }
        cout << "\n中序线索化完成" << endl;
    }

    // 7. 根据前序和中序序列重建二叉树
    TreeNode* buildTreeHelper(string& preorder, string& inorder,
                            int preStart, int preEnd,
                            int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* node = new TreeNode(preorder[preStart]);
        int rootPos = inorder.find(preorder[preStart]);
        if (rootPos == string::npos) return nullptr;

        int leftSubtreeSize = rootPos - inStart;

        node->left = buildTreeHelper(preorder, inorder,
                                   preStart + 1, preStart + leftSubtreeSize,
                                   inStart, rootPos - 1);
        node->right = buildTreeHelper(preorder, inorder,
                                    preStart + leftSubtreeSize + 1, preEnd,
                                    rootPos + 1, inEnd);
        return node;
    }

    void rebuildFromTraversals() {
        string preorder = "ABCDEGF";
        string inorder = "CBEGDFA";

        if (preorder.length() != inorder.length()) {
            cout << "序列长度不匹配！" << endl;
            return;
        }

        destroyTree(root);
        try {
            root = buildTreeHelper(preorder, inorder, 0, preorder.length()-1,
                                 0, inorder.length()-1);
            cout << "\n重建二叉树完成,遍历结果:" << endl;
            printAllTraversals();
        } catch (...) {
            cout << "重建过程发生错误!" << endl;
            root = nullptr;
        }
    }
};

int main() {
    BinaryTree tree;

    // 1. 创建二叉树并显示三种遍历
    tree.createBinaryTree();
    cout << "\n1. 基本遍历结果:";
    tree.printAllTraversals();

    // 2. 输出叶子节点数
    cout << "\n2. 叶子节点数:" << tree.getLeafCount() << endl;

    // 3. 输出树的高度
    cout << "\n3. 树的高度:" << tree.getTreeHeight() << endl;

    // 4. 交换左右子树并显示前序和中序遍历结果
    cout << "\n4. 交换左右子树结果:";
    tree.swapAndPrint();

    // 5. 输出非递归后序遍历
    cout << "\n5. 后序遍历结果:";
    tree.nonRecursivePostOrder();

    // 6. 中序线索化
    cout << "\n6. 创建中序线索二叉树:";
    tree.createInorderThread();

    // 7. 测试根据遍历序列重建二叉树
    cout << "\n7. 重建二叉树测试:";
    tree.rebuildFromTraversals();

    return 0;
}