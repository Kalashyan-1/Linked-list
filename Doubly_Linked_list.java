class Doubly_Linked_list<T> {
	
	Node<T> head;
	Node<T> tail;
Doubly_Linked_list() {
	this.head = null;
	this.head = null;
}
	class Node<T> {
        T value;
        Node<T> prev;
        Node<T> next;

         Node(T value) {
            this.value = value;
			this.prev = null;
			this.next = null;        }
    }

    void insert(T value) {
        Node<T> node = new Node<>(value);

        if(head == null) {
            head = tail = node;
            head.prev = null;
            tail.next = null;
        }
        else {
            tail.next = node;
            node.prev = tail;
            tail = node;
            tail.next = null;
        }
    }

	 void delete() {
        if(head == null) {
            return;
        } else {
            if(head != tail) {
                tail = tail.prev;
                tail.next = null;
            }
            else {
                head = null;
				tail = null;
            }
        }
	 }

     void print() {
        Node<T> tmp = head;
        if(head == null) {
            return;
        }
        while(tmp != null) {
            System.out.print(tmp.value + " ");
            tmp = tmp.next;
        }
    }


    public static void main(String[] args) {
        Doubly_Linked_list<Integer> list = new Doubly_Linked_list<>();
        list.insert(10);
        list.insert(10);
		list.delete();
        list.print();

		Doubly_Linked_list<String> list2 = new Doubly_Linked_list<>();
        list2.insert("String1");
        list2.insert("String2");
		list2.delete();
        list2.print();

    }
}
