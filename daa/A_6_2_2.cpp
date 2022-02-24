#include <iostream>

using namespace std;
int list[1000], ind = 0;

class node
{
public:
    int data;
    node *left_node;
    node *right_node;
};
node *Create_node(int d)
{
    node *newnode = new node;
    newnode->data = d;
    newnode->left_node = NULL;
    newnode->right_node = NULL;
    return newnode;
}
node *Insert(node *root, int d)
{
    node *temp = Create_node(d);
    node *tree = new node;
    tree = root;
    if (root == NULL)
        root = temp;
    else
    {
        while (tree != NULL)
        {
            if (tree->data < d)
            {
                if (tree->right_node == NULL)
                {
                    tree->right_node = temp;
                    break;
                }
                tree = tree->right_node;
            }
            else if (tree->data > d)
            {
                if (tree->left_node == NULL)
                {
                    tree->left_node = temp;
                    break;
                }
                tree = tree->left_node;
            }
        }
    }
    return root;
}
int Search(node *root, int d)
{
    int depth = 0;
    node *temp = new node;
    temp = root;
    while (temp != NULL)
    {
        depth++;
        if (temp->data == d)
        {
            // cout<<"\nitem found at depth: "<<depth;
            return depth;
        }
        else if (temp->data > d)
            temp = temp->left_node;
        else
            temp = temp->right_node;
    }
    cout << "\n Not found";
    return 0;
}
//-----------------
int Finding_Frequencyuency(int Frequencyuency_Array[], int start, int end)
{
    int fmax = Frequencyuency_Array[start];
    int ind = start;
    for (int i = start; i < end; i++)
    {
        if (Frequencyuency_Array[i] > fmax)
        {
            fmax = Frequencyuency_Array[i];
            ind = i;
        }
    }
    return ind;
}
void BST_TREE_MAKER(node *root, int array[], int key_Array[], int start, int end)
{
    if (start != end)
    {
        int partition = Finding_Frequencyuency(array, start, end);
        list[ind] = partition;
        ind++;
        BST_TREE_MAKER(root, array, key_Array, start, partition);
        BST_TREE_MAKER(root, array, key_Array, partition + 1, end);
    }
}

int main()
{
    char ch;
    int size;
    int n, i;
    // int key[7]={0,1,2,3,4,5,6};
    // int Frequency[7]={22,18,20,5,25,2,8};
    cout << "\nEnter size of the array you want to make : ";
    cin >> size;
    int key[size], Frequency[size];
    //--------------------------------------------------------inputs-------------------
    cout << "\nEnter the key array : ";
    for (i = 0; i < size; i++)
        cin >> key[i];

    cout << "\nEnter the Frequency array : ";
    for (i = 0; i < size; i++)
        cin >> Frequency[i];
    //--------------------------------------bubble sorting ----------------------------------------------
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
        {
            if (key[x] < key[y])
            {
                int temp = key[x];
                int Ftemp = Frequency[x];
                key[x] = key[y];
                Frequency[x] = Frequency[y];
                key[y] = temp;
                Frequency[y] = Ftemp;
            }
        }
    //-------------------------------printing key and Frequencyuency--------------------------------
    cout << "------Frequency Table-------\n";
    for (int x = 0; x < size; x++)
    {
        cout << "\n      " << key[x] << " <----> " << Frequency[x];
    }
    node *root = new node;
    root = NULL;
    BST_TREE_MAKER(root, Frequency, key, 0, size);
    cout << "\nThe ordered Key list in Frequency order is : ";
    for (int j = 0; j < size; j++)
        cout << "    " << list[j];

    for (i = 0; i < size; i++)
    {
        root = Insert(root, key[list[i]]);
    }
    int sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += Search(root, key[list[i]]) * key[list[i]];
    }
    cout << " \n cost is : " << sum;
    return 0;
}