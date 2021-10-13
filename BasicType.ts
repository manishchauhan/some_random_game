//1 CREATE A INTERFACE
interface Human {
    name: string;
    age: number;
  }
  const human = {
    name: 'manish',
    age: 34,
  };
  console.log(human.name);
  
  //2. create your own type
  type numberstringUnion = number | string;
  const username: numberstringUnion = 'manish';
  const age: numberstringUnion = 22;
  //console.log(username + '' + age);
  
  //3. intersection type
  const fetechData = async (url: string) => {
    const jsonData = await fetch(url);
    const data = await jsonData.json();
    return data;
  };
  
  //take any type of data either Post or Comment
  interface Post {
    userId: string | number;
    id: string | number;
    title: string;
    body?: string;
  }
  interface Comment {
    postId: string | number;
    id: string | number;
    name: string;
    email: string;
    body: string;
  }
  type mixed = Post & Comment;
  fetechData(`https://jsonplaceholder.typicode.com/posts`)
    .then((data: mixed) => {
      console.log(data[0].id);
    })
    .catch((error: Error) => {
      console.log(error);
    });
  
  //genric
  