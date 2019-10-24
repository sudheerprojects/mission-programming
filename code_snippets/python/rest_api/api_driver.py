import requests
import json

put = requests.put("http://127.0.0.1:5000/todo", data={'task': 'Remember the milk'})
print("Response ", put.text)
get = requests.get("http://127.0.0.1:5000/todo1")
print(get.text)

