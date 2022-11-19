package com.example.practical_7_phone_call;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {
    EditText ed1;
    Button bt;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ed1 = findViewById(R.id.num);
        bt = findViewById(R.id.btn);

        bt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String number = ed1.getText().toString();
                Intent i = new Intent(Intent.ACTION_CALL, Uri.parse("tel:" + number));

                startActivity(i);
                if (ActivityCompat.checkSelfPermission(MainActivity.this,
                        Manifest.permission.CALL_PHONE) != PackageManager.PERMISSION_GRANTED) {
                    return;
                }
                startActivity(i);
            }
        });
    }
}