package com.example.practical_8_1_email_client;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;
import com.google.android.material.button.MaterialButton;


public class MainActivity extends AppCompatActivity {
    EditText em, sb, msg;
    MaterialButton bt;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        bt = findViewById(R.id.btn);
        em = findViewById(R.id.email);
        sb = findViewById(R.id.sub);
        msg = findViewById(R.id.msg);

        bt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String email = em.getText().toString();
                String subject = sb.getText().toString();
                String message = msg.getText().toString();
                if(email.equals("")||subject.equals("")||message.equals(""))
                {
                    Toast.makeText(MainActivity.this, "Enter all the fields",
                            Toast.LENGTH_SHORT).show();
                }
                else
                {
                    Intent intent = new Intent(Intent.ACTION_SEND);
                    intent.putExtra(Intent.EXTRA_EMAIL, new String[]{email});
                    intent.putExtra(Intent.EXTRA_SUBJECT, subject);
                    intent.putExtra(Intent.EXTRA_TEXT, message);
                    intent.setType("message/rfc822");
                    startActivity(Intent.createChooser(intent,"Choose an email client"));
                }
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.activity_main, menu);
        return true;
    }
}
