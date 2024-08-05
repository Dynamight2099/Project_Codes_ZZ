class Node<T> {
    T data;
    Node<T> next;

    public Node(T data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList<T> {
    private Node<T> head;

    public void add(T data) {
        Node<T> newNode = new Node<>(data);
        if (head == null) {
            head = newNode;
        } else {
            Node<T> current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    public void print() {
        Node<T> current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}

public class GenericClassExample {
    public static void main(String[] args) {
        // Creating a linked list of integers
        LinkedList<Integer> intList = new LinkedList<>();
        intList.add(1);
        intList.add(2);
        intList.add(3);

        // Creating a linked list of strings
        LinkedList<String> strList = new LinkedList<>();
        strList.add("Hello");
        strList.add("LinkedList");
        strList.add("!");

        // Printing the elements of the linked lists
        System.out.println("Elements of Integer Linked List:");
        intList.print();

        System.out.println("\nElements of String Linked List:");
        strList.print();
    }
}
