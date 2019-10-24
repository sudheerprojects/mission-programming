from pymongo import MongoClient
client = MongoClient()
db = client.amadeus
#result = db.emp.insert({"empId":655, "empName":"Saritha", "salary":2000})
result = db.emp.find({"empId":{"$gt":105}})
for res in result:
    print(res)

client.close()

