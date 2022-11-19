package com.example.myapp;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
public class MainActivity2 extends AppCompatActivity {
    TextView tv1, tv2, tv3, tv4, tv5;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        tv1 = findViewById(R.id.myfname);
        tv2 = findViewById(R.id.mylname);
        tv3 = findViewById(R.id.myusername);
        tv4 = findViewById(R.id.mypassword);
        tv5 = findViewById(R.id.myemail);
        Bundle extras = getIntent().getExtras();
        if(extras!=null)
        {
            String fName = extras.getString("fName");
            tv1.setText(tv1.getText().toString() + fName);
            String lName = extras.getString("lName");
            tv2.setText(tv2.getText().toString() + lName);
            String userName = extras.getString("userName");
            tv3.setText(tv3.getText().toString() + userName);
            String password = extras.getString("password");
            tv4.setText(tv4.getText().toString() + password);
            String emailID = extras.getString("emailID");
            tv5.setText(tv5.getText().toString() + emailID);
        }
    }
}
