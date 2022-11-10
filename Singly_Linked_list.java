class Singly_Linked_list<T> {
			
			Node<T> head;
			Singly_Linked_list() {
				this.head = null;
			}
			class Node<t> {
				T value;
				Node<T> next;
				Node(T v) {
					this.value = v;
					this.next = null;
				}

			}
			void push(T value) { 

				Node<T> tmp = new Node<>(value);
				if (this.head == null) {
					head = tmp;
				} else {
					Node<T> n = head;
					while(n.next != null) {
						n = n.next;
				}
				n.next = tmp;
				}
			}

			void pop() {
				System.out.println("aaa");
				Node<T> last = new Node<T>(null);
				if (this.head.next == null || this.head == null) {
					this.head = last;
					return;
				}
				Node<T> n = head;
				while (n.next.next != null) {
				
					System.out.println("bb");
					n = n.next;
				}
				n.next = null;
			}

			void print() {
				Node<T> node = head;
				while (node != null) {
					System.out.print(node.value + " ");
					node = node.next;
				}
			}

			public static void main(String[] args) {
				Singly_Linked_list<Integer> list = new Singly_Linked_list<>();
				list.push(11);
				list.push(12);
				list.pop();
				list.print();
				Singly_Linked_list<String> list2 = new Singly_Linked_list<>();
				list2.push("String");
				list2.push("String2");
				list2.pop();
				list2.print();


			}
}



	

