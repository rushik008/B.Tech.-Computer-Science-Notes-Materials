package com.example.practical_8_2_passing_data;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import com.google.android.material.button.MaterialButton;
public class MainActivity extends AppCompatActivity {
    EditText ed;
    MaterialButton bt;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ed = findViewById(R.id.text);
        bt = findViewById(R.id.btn);
        bt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String name = ed.getText().toString();
                Intent intent = new Intent(MainActivity.this, MainActivity2.class);
                intent.putExtra("Name",name);
                startActivity(intent);
            }
        });
    }
}
