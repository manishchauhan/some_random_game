// Import stylesheets
import './style.css';

// Write TypeScript code!
//A linked List with all solution in typescript

//create a Node class which store linked list node
class Node<T> {
  data: T;
  next: Node<T>;
}

class LinkedList<T> {
  //define a head
  head: Node<T>;
  tail: Node<T>;
  constructor() {
    this.head = null;
    this.head = null;
  }
  //add a node to the linked list
  appendNode(_data: T) {
    const node = new Node<T>();
    node.data = _data;
    if (this.head === null) {
      this.head = node;
      this.tail = node;
    } else {
      this.tail.next = node;
      this.tail = node;
    }
  }
  display() {
    let current = this.head;
    while (current != null) {
      console.log(current.data);
      current = current.next;
    }
  }
  //reverse a linked list
  reverse() {
    let current = this.head;
    let next = null;
    let prev = null;
    while (current != null) {
      next = current.next;
      current.next = prev;
      prev = current;
      current = next;
    }
    this.head = prev;
  }
  //delete a node in linked list
  delete(_value: T) {
    //check if value in head move it to next util values mactes
    while (this.head.data == _value) {
      this.head = this.head.next;
    }
    let current = this.head;
    while (current.next != null) {
      if (current.next.data === _value) {
        current.next = current.next.next;
      } else {
        current = current.next;
      }
    }
  }

  //insert afer
  insertAfter(_value: T, _data: T) {
    let current = this.head;
    while (current != null) {
      if (current.data === _value) {
        break;
      }
      current = current.next;
    }
    if (current === null) {
      return 'opps';
    }
    const node = new Node<T>();
    node.data = _data;
    node.next = current.next;
    current.next = node;
  }
  //insert before
}

let list: LinkedList<string> = new LinkedList<string>();
list.appendNode('a');
list.appendNode('b');
list.appendNode('c');
list.appendNode('d');
//list.insertAfter("b", "xyz");
list.display();
