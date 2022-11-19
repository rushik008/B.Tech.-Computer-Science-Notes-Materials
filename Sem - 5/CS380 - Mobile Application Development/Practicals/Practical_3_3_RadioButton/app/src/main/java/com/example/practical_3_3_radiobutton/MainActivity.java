package com.example.practical_3_3_radiobutton;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    RadioButton cse, ce, it;
    String selectedSuperStar;
    Button submit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        cse = (RadioButton) findViewById(R.id.cse);
        ce = (RadioButton) findViewById(R.id.ce);
        it = (RadioButton) findViewById(R.id.it);

        submit = (Button) findViewById(R.id.submitButton);

        submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (cse.isChecked()) {
                    selectedSuperStar = cse.getText().toString();
                } else if (ce.isChecked()) {
                    selectedSuperStar = ce.getText().toString();
                } else if (it.isChecked()) {
                    selectedSuperStar = it.getText().toString();
                }
                Toast.makeText(getApplicationContext(), selectedSuperStar, Toast.LENGTH_LONG).show(); // print the value of selected super star
            }
        });

    }
}