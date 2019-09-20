[![NPM](https://nodei.co/npm/keys_deep.png?stars&downloads)](https://nodei.co/npm/keys_deep/)
[![NPM](https://nodei.co/npm-dl/keys_deep.png)](https://nodei.co/npm/keys_deep/)

returns an array of strings that contains all the keys of the object in the form ['key1', 'obj.key11'].

## Usage

```javascript

var obj = {
  "name": "Jessie J",
  "rating": 69,
  "image_path": "/test.jpg",
  "alternative_name": null,
  "alternative_name2": undefined,
  "obj": {
    "23": {
      "yo": "lol"
    }
  },
  "objectID": "551491260"
}

console.log(keysDeep(a));
/*
[ 'name',
  'rating',
  'image_path',
  'alternative_name',
  'alternative_name2',
  'obj.23.yo',
  'objectID'
]
*/
```
