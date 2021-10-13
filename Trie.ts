//A Trie build in typescript
//most of the time is string
class TrieNode<T> {
    private _isWordEnd: boolean = false;
    private _data;
    public nodesMap: Map<string, TrieNode<T>> = new Map();
    constructor() {}
    //check if work is ended or not
    get isWordEnd() {
      return this._isWordEnd;
    }
    set isWordEnd(status: boolean) {
      this._isWordEnd = status;
    }
    set data(data: string) {
      this._data = data;
    }
    get data() {
      return this._data;
    }
    //make a BFS
    BFS(data: string): Array<T> {
      let results = [];
      let queue = [];
      let node: TrieNode<T> = this;
      let keys = [];
  
      queue.push({ str: data, current: node });
      while (queue.length) {
        let ref = queue.pop();
        let selectedNode = ref.current;
        let str = ref.str;
        if (selectedNode.isWordEnd) {
          results.push(str);
        }
        selectedNode.nodesMap.forEach((node, key) => {
          queue.push({ str: str + node.data, current: node });
        });
      }
      return results;
    }
    //delete
    deleteNode(data: string): string | boolean {
      let wordsMap = {};
      const lastword = data[data.length - 1];
      let status = false;
      let queue = [];
      let currentNode = this;
      queue.push(currentNode);
      while (queue.length) {
        let node = queue.pop();
  
        if (node.isWordEnd) {
          if (node.data === lastword) {
            node.isWordEnd = false;
            node.data = undefined;
            status = true;
          }
        }
  
        node.nodesMap.forEach((item) => {
          if (item.nodesMap.size === 0) {
            if (data.includes(item.data)) {
              node.data = undefined;
            }
          }
          queue.push(item);
        });
      }
      return status;
    }
  }
  //Trie class
  class Trie<T> {
    //we need root
    public rootNode: TrieNode<T> = null;
  
    public newNode(): TrieNode<T> {
      const node = new TrieNode<T>();
      node.isWordEnd = false;
      return node;
    }
    constructor() {
      //root node
    }
    getNull() {
      if (this.rootNode === null) {
        return true;
      }
    }
    insert(data: string) {
      if (this.rootNode == null) {
        this.rootNode = this.newNode();
      }
      let currentNode = this.rootNode;
      for (let i = 0; i < data.length; i++) {
        const key = data[i];
        if (!currentNode.nodesMap.has(key)) {
          let newNode = this.newNode();
          currentNode.nodesMap.set(key, newNode);
          newNode.data = key;
        }
        currentNode = currentNode.nodesMap.get(key);
      }
  
      currentNode.isWordEnd = true;
    }
    //search a word
    search(data: string) {
      if (this.getNull()) {
        return 'EMPTY TRIE NO OPERATION CAN BE DONCE';
      }
      let currentNode = this.rootNode;
      for (let i = 0; i < data.length; i++) {
        const key = data[i];
        if (!currentNode.nodesMap.has(key)) {
          return false;
        }
        currentNode = currentNode.nodesMap.get(key);
      }
  
      return currentNode.isWordEnd;
    }
    //auto
    autoComplete(data: string): Array<T> | string {
      if (this.getNull()) {
        return 'EMPTY TRIE NO OPERATION CAN BE DONCE';
      }
      let result = [];
      let currentNode = this.rootNode;
      for (let i = 0; i < data.length; i++) {
        const key = data[i];
        if (!currentNode.nodesMap.has(key)) {
          return result;
        }
        currentNode = currentNode.nodesMap.get(key);
      }
  
      return currentNode.BFS(data);
    }
    //delete a node
    deleteNode(data: string): string | boolean {
      if (this.getNull()) {
        return 'EMPTY TRIE NO OPERATION CAN BE DONCE';
      }
      let result = [];
      let currentNode = this.rootNode;
      for (let i = 0; i < data.length; i++) {
        const key = data[i];
        if (!currentNode.nodesMap.has(key)) {
          return 'NOT FOUND';
        }
        currentNode = currentNode.nodesMap.get(key);
      }
  
      return this.rootNode.deleteNode(data);
    }
    //display Trie
    display() {
      return this.rootNode.BFS(this.rootNode.data).map((item) => {
        return String(item).substring(9);
      });
    }
  }
  
  let trie = new Trie<string>();
  
  trie.insert('manu');
  trie.insert('manuxyz');
  trie.insert('manish');
  trie.insert('deepak');
  trie.insert('maa');
  trie.insert('xyz');
  trie.insert('sachin');
  trie.insert('sanju');
  trie.insert('sanjayrawat');
  
  //console.log(trie.deleteNode("maa"));
  console.log(trie.autoComplete('ma'));
  //console.log(trie.display());
  