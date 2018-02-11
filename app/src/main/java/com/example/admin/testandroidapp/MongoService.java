package com.example.admin.testandroidapp;


import android.os.Build;

import com.mongodb.MongoClient;
import com.mongodb.MongoClientURI;

import org.bson.Document;
import org.bson.types.ObjectId;

public class MongoService {
    private MongoClient mongoClient;

    public void sendInfo(String testType, String library, long result){
        MongoClientURI mongoClientURI = new MongoClientURI("mongodb://admin:admin@androidtestbase-shard-00-00-zei2i.mongodb.net:27017,androidtestbase-shard-00-01-zei2i.mongodb.net:27017,androidtestbase-shard-00-02-zei2i.mongodb.net:27017/test?ssl=true&replicaSet=AndroidTestBase-shard-0&authSource=admin");
        mongoClient = new MongoClient(mongoClientURI);
        ObjectId deviceId = sendAndroidInfo();

        Document document = new Document()
                .append("Device", deviceId)
                .append("testType", testType)
                .append("library", library)
                .append("result", result);

        mongoClient.getDatabase("Android").getCollection("Tests").insertOne(document);
    }

    private ObjectId sendAndroidInfo(){
        Document document = new Document()
                .append("Brand", Build.BRAND)
                .append("Model", Build.MODEL)
                .append("AndroidVersion", Build.VERSION.RELEASE)
                .append("Product", Build.PRODUCT)
                .append("Radio", Build.RADIO);

        mongoClient.getDatabase("Android").getCollection("Devices").insertOne(document);

        return (ObjectId) document.get("_id");
    }
}
