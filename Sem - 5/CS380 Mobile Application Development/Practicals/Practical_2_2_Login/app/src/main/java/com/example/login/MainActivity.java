package com.example.login;

import androidx.appcompat.app.AppCompatActivity;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    Button bt1, bt2;
    EditText edt1, edt2;
    TextView tx1,tx2;
    int counter = 3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edt1 = (EditText)findViewById(R.id.EmailEditText);
        edt2 = (EditText)findViewById(R.id.PasswordEditText);

        tx1 = (TextView)findViewById(R.id.TextViewNoOfAttempts);
        tx2 = (TextView)findViewById(R.id.TextViewStatusResult);

        bt1 = (Button)findViewById(R.id.LoginBtn);
        bt2 = (Button)findViewById(R.id.CancelBtn);

        bt1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (edt1.getText().toString().equals("rushik") && edt2.getText().toString().equals("rushik")) {
                    Toast.makeText(getApplicationContext(), "Login Successful", Toast.LENGTH_SHORT).show();
                    tx2.setVisibility(View.VISIBLE);
                    tx2.setBackgroundColor(Color.GREEN);
                    tx2.setText("Login Successful!");
                }
                else {
                    tx2.setVisibility(View.VISIBLE);
                    tx2.setText("Login Failed!");
                    tx2.setBackgroundColor(Color.RED);
                    Toast.makeText(getApplicationContext(), "Wrong Credentials", Toast.LENGTH_SHORT).show();
                    counter--; // number of attempts
                    tx1.setText(Integer.toString(counter));

                    if(counter == 0)
                    {
                        bt1.setEnabled(false);
                        Toast.makeText(getApplicationContext(), "Login Disabled!", Toast.LENGTH_SHORT).show();
                    }
                }
            }
        });

        bt2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });
    }
}