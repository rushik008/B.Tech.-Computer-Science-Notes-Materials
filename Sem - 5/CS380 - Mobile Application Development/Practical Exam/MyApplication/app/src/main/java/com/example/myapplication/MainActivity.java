package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {

    EditText edt1;
    Button btn1;
    TextView ans1, ans2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edt1 = (EditText) findViewById(R.id.edtEnterKms);
        Button btn1 = (Button) findViewById(R.id.btnResult);
        ans1 = (TextView) findViewById(R.id.txtAnsMeter);
        ans2 = (TextView) findViewById(R.id.txtAnsCm);

        btn1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if (edt1.getText().length() > 0) {

                    double opr1 = Double.parseDouble(edt1.getText().toString());
                    double res1 = opr1*1000;
                    double res2 = res1*100;
                    ans1.setVisibility(View.VISIBLE);
                    ans2.setVisibility(View.VISIBLE);
                    ans1.setText(Double.toString(res1));
                    ans2.setText(Double.toString(res2));
                } else {
                    Toast toast = Toast.makeText(MainActivity.this, "Enter The Required Numbers", Toast.LENGTH_LONG);
                    toast.show();
                }
            }
        });

    }
}