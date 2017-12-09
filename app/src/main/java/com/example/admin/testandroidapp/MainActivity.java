package com.example.admin.testandroidapp;


import android.os.Bundle;
import android.widget.TabHost;
import android.widget.TextView;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setTitle("TabHost");

        TabHost tabHost = (TabHost) findViewById(R.id.tabHost);

        tabHost.setup();

        TabHost.TabSpec tabSpec = tabHost.newTabSpec("tag1");
        tabSpec.setContent(R.id.fibonacci);
        tabSpec.setIndicator("Fibonacci");
        tabHost.addTab(tabSpec);

        tabSpec = tabHost.newTabSpec("tag2");
        tabSpec.setContent(R.id.tab2);
        tabSpec.setIndicator("2D");
        tabHost.addTab(tabSpec);

        tabSpec = tabHost.newTabSpec("tag3");
        tabSpec.setContent(R.id.tab3);
        tabSpec.setIndicator("Internet");
        tabHost.addTab(tabSpec);

        tabHost.setCurrentTab(0);
        //Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        //setSupportActionBar(toolbar);

       //FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
//        fab.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
//                        .setAction("Action", null).show();
//            }
//        });

    // Example of a call to a native method
    TextView tv = (TextView) findViewById(R.id.fibonacciTextJava);
//    tv.setText(stringFromJNI());
    Fibonacci fibo = new Fibonacci();
//        tv.setText(Long.toString(fibo.getFibonacci(10)));
//        tv.setText(fibonacci(new Long(10)).toString());

//    tv.setText(Long.toString(fibo(100)));
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void onFibonacciButtonJava(View view) {
        TextView tv = (TextView) findViewById(R.id.fibonacciTextJava);
        tv.setText(Long.toString(new Fibonacci().getFibonacci(10)));
    }

    public void onFibonacciButtonNative(View view) {
        TextView tv = (TextView) findViewById(R.id.fibonacciTextNative);
        int num= 10;
        tv.setText(Integer.toString(fibo(num)));

    }



    static {
        System.loadLibrary("native-lib");
//        System.loadLibrary("Fibonacci.h");
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    //public native String stringFromJNI();
//    public native Long fibonacci(long num);
   // public static native long fibonacci(String num);
    public static native int fibo(int num);

    // Used to load the 'native-lib' library on application startup
}
