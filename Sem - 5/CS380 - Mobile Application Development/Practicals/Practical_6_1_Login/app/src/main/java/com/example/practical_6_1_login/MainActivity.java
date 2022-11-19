package com.example.practical_6_1_login;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {
    EditText edtEmail, edtPassword;
    Button btnLogin;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edtEmail = (EditText) findViewById(R.id.EmailEditText);
        edtPassword = (EditText) findViewById(R.id.PasswordEditText);

        btnLogin = (Button) findViewById(R.id.LoginBtn);
        edtPassword.addTextChangedListener(TextChange);
        edtEmail.addTextChangedListener(TextChange);
        check();
    }

    private TextWatcher TextChange=new TextWatcher() {
        @Override
        public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

        }

        @Override
        public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {

        }

        @Override
        public void afterTextChanged(Editable editable) {
            check();
        }
    };

    public void check(){
        if(edtEmail.getText().toString().equals("rushik") && edtPassword.getText().toString().equals("rushik")){

            btnLogin.setEnabled(true);

            btnLogin.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                        Toast.makeText(getApplicationContext(), "Login Successful", Toast.LENGTH_SHORT).show();
                        Intent intent = new  Intent(getBaseContext(), MainActivity2.class);
                        startActivity(intent);
                }
            });
        }
        else{
            btnLogin.setEnabled(false);
        }
    }
}