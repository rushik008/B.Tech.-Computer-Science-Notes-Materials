package com.example.practical_8_2_passing_data;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
public class MainActivity2 extends AppCompatActivity {
    TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        textView = findViewById(R.id.textView);
        Bundle extras = getIntent().getExtras();
        if(extras!=null)
        {
            String Name = extras.getString("Name");
            textView.setText(textView.getText().toString() + Name);
        }
    }
}
