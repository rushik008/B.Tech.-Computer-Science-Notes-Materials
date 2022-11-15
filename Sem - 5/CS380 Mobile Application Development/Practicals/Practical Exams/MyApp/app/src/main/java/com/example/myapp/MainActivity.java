package com.example.myapp;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.material.button.MaterialButton;

public class MainActivity extends AppCompatActivity {
    EditText ed1,ed2, ed3,ed4,ed5, ed6;
    MaterialButton bt;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ed1 = (EditText)findViewById(R.id.fname);
        ed2 = (EditText)findViewById(R.id.lname);
        ed3 = (EditText)findViewById(R.id.username);
        ed4 = (EditText)findViewById(R.id.password);
        ed5 = (EditText)findViewById(R.id.canfirmpassword);
        ed6 = (EditText)findViewById(R.id.emailID);
        bt = (MaterialButton) findViewById(R.id.btn);

        bt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String fname = ed1.getText().toString();
                String lname = ed2.getText().toString();
                String username = ed3.getText().toString();
                String password = ed4.getText().toString();
                String canfirmpassword = ed5.getText().toString();
                String emailID = ed6.getText().toString();


                if (ed4.getText().toString().equals("rushik") && ed5.getText().toString().equals("rushik")&& ed6.getText().toString().equals("rushik@gmail.com")) {
                    Toast.makeText(getApplicationContext(), "Registration Successful", Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent(MainActivity.this, MainActivity2.class);
                    intent.putExtra("fName",fname);
                    intent.putExtra("lName",lname);
                    intent.putExtra("userName",username);
                    intent.putExtra("password",password);
                    intent.putExtra("emailID",emailID);
                    startActivity(intent);
                }
                else
                {
                    Toast.makeText(getApplicationContext(), "Wrong Credential", Toast.LENGTH_SHORT).show();

                }
            }
        });
    }
}
