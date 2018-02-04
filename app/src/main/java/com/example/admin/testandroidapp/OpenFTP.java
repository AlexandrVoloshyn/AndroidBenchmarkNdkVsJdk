package com.example.admin.testandroidapp;

import android.content.Context;
import android.os.AsyncTask;
import android.os.Environment;
import android.support.v4.app.ActivityCompat;

import org.apache.commons.net.ftp.FTPClient;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.InetAddress;

/**
 * Created by Admin on 04.02.2018.
 */

public class OpenFTP extends AsyncTask<Void, Void, File> {

    private Context context;

    public OpenFTP(Context context){
        super();
        this.context = context;
    }


    @Override
    protected File doInBackground(Void... voids) {
        FTPClient ftpClient = null;
        try {
            ftpClient = new FTPClient();
            ftpClient.setConnectTimeout(10*1000);
            ftpClient.connect(InetAddress.getByName("speedtest.tele2.net"));
            ftpClient.login("anonymous", "anonymous@anonymous.com");

            ftpClient.setFileType(FTPClient.BINARY_FILE_TYPE);
            ftpClient.enterLocalPassiveMode();

            OutputStream outputStream = null;
            boolean success = false;

            File root = Environment.getExternalStorageDirectory();

            outputStream = new BufferedOutputStream((new FileOutputStream(root.getAbsolutePath() + File.separator + "test.zip")));
            success = ftpClient.retrieveFile("/100KB.zip", outputStream);


        } catch (IOException e) {
            e.printStackTrace();
        }


        return null;
    }
}
