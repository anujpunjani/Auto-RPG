typedef struct LinkedList *LinkedListPointer;
typedef struct LinkedList LinkedListType;

typedef struct Mayhem *MayhemPointer;
typedef struct Mayhem MayhemType;

int createLinkedList(LinkedListPointer *, void *);
int insertNodeAtFront(LinkedListPointer *, void *);
void FreeAllocatedMemory(LinkedListPointer *);

struct Mayhem
{
    int hp;
    int atk;
    int def;
    int med;
    char hm_name[50];
};

struct LinkedList
{
    void *data;
    LinkedListPointer next;
};