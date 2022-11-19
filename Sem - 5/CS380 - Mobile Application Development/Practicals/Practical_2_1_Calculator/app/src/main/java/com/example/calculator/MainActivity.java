package com.example.calculator;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    EditText edt1, edt2;
    Button btnadd, btnsub, btnmul, btndiv;
    TextView txtans;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edt1 = (EditText) findViewById(R.id.edtNumberOne);
        edt2 = (EditText) findViewById(R.id.edtNumberTwo);
        btnadd = (Button) findViewById(R.id.btnadd);
        btnsub = (Button) findViewById(R.id.btnsub);
        btnmul = (Button) findViewById(R.id.btnmul);
        btndiv = (Button) findViewById(R.id.btndiv);
        txtans = (TextView) findViewById(R.id.txtans);

        // Addition
        btnadd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if ((edt1.getText().length() > 0) && (edt2.getText().length() > 0)) {
                    double oper1 = Double.parseDouble(edt1.getText().toString());
                    double oper2 = Double.parseDouble(edt2.getText().toString());
                    double result = oper1 + oper2;
                    txtans.setVisibility(View.VISIBLE);
                    txtans.setText(Double.toString(result));
                } else {
                    Toast toast = Toast.makeText(MainActivity.this, "Enter The Required Numbers", Toast.LENGTH_LONG);
                    toast.show();
                }
            }
        });

        //Subtraction
        btnsub.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if ((edt1.getText().length() > 0) && (edt2.getText().length() > 0)) {
                    double oper1 = Double.parseDouble(edt1.getText().toString());
                    double oper2 = Double.parseDouble(edt2.getText().toString());
                    double result = oper1 - oper2;
                    txtans.setVisibility(View.VISIBLE);
                    txtans.setText(Double.toString(result));
                } else {
                    Toast toast = Toast.makeText(MainActivity.this, "Enter The Required Numbers", Toast.LENGTH_LONG);
                    toast.show();
                }

            }
        });

        // Multiplication
        btnmul.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if ((edt1.getText().length() > 0) && (edt2.getText().length() > 0)) {
                    double oper1 = Double.parseDouble(edt1.getText().toString());
                    double oper2 = Double.parseDouble(edt2.getText().toString());
                    double result = oper1 * oper2;
                    txtans.setVisibility(View.VISIBLE);
                    txtans.setText(Double.toString(result));
                } else {
                    Toast toast = Toast.makeText(MainActivity.this, "Enter The Required Numbers", Toast.LENGTH_LONG);
                    toast.show();
                }
            }
        });

        // Division
        btndiv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if ((edt1.getText().length() > 0) && (edt2.getText().length() > 0)) {
                    double oper1 = Double.parseDouble(edt1.getText().toString());
                    double oper2 = Double.parseDouble(edt2.getText().toString());
                    double result = oper1 / oper2;
                    txtans.setVisibility(View.VISIBLE);
                    txtans.setText(Double.toString(result));
                } else {
                    Toast toast = Toast.makeText(MainActivity.this, "Enter The Required Numbers", Toast.LENGTH_LONG);
                    toast.show();
                }
            }
        });
    }
}