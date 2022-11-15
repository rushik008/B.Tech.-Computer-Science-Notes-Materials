package com.example.practical_9_sql_db;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
public class MainActivity extends AppCompatActivity {
    Button insert, update, view, delete;
    EditText id, name, surname, marks;
    DBHelper DB;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        insert = findViewById(R.id.insert);
        update = findViewById(R.id.update);
        view = findViewById(R.id.view);
        delete = findViewById(R.id.delete);
        id = findViewById(R.id.id);
        name = findViewById(R.id.name);
        surname = findViewById(R.id.surname);
        marks = findViewById(R.id.marks);
        DB = new DBHelper(this);
        insert.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String Id = id.getText().toString();
                String Name = name.getText().toString();
                String Surname = surname.getText().toString();
                String Marks = marks.getText().toString();
                Boolean checkInsert = DB.InsertData(Id,Name, Surname, Marks);
                if(checkInsert==true)
                {
                    Toast.makeText(MainActivity.this, "Data inserted successfully!",
                            Toast.LENGTH_SHORT).show();
                }
                else
                {
                    Toast.makeText(MainActivity.this, "Cannot insert data",
                            Toast.LENGTH_SHORT).show();
                }
            }
        });
        update.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String Id = id.getText().toString();
                String Name = name.getText().toString();
                String Surname = surname.getText().toString();
                String Marks = marks.getText().toString();
                Boolean checkUpdate = DB.UpdateDate(Id, Name, Surname, Marks);
                if(checkUpdate==true)
                {
                    Toast.makeText(MainActivity.this, "Data updated successfully",
                            Toast.LENGTH_SHORT).show();
                }
                else
                {
                    Toast.makeText(MainActivity.this, "Unable to update data1!",
                            Toast.LENGTH_SHORT).show();
                }
            }
        });
        view.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Cursor res = DB.ViewData();
                if(res.getCount()==0)
                {
                    Toast.makeText(MainActivity.this, "No data exists",
                            Toast.LENGTH_SHORT).show();
                    return;
                }
                StringBuffer buffer = new StringBuffer();
                while(res.moveToNext())
                {
                    buffer.append("Id: "+res.getString(0)+"\n");
                    buffer.append("Name: "+res.getString(1)+"\n");
                    buffer.append("Surname: "+res.getString(2)+"\n");
                    buffer.append("Marks: "+res.getString(3)+"\n");
                }
                AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
                builder.setCancelable(true);
                builder.setTitle("User data");
                builder.setMessage(buffer.toString());
                builder.show();
            }
        });
        delete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String Id = id.getText().toString();
                if(Id.equals(""))
                {
                    Toast.makeText(MainActivity.this, "Please enter ID",
                            Toast.LENGTH_SHORT).show();
                }
                else
                {
                    Boolean checkDelete = DB.DeleteDate(Id);
                    if(checkDelete==true)
                    {
                        Toast.makeText(MainActivity.this, "Data deleted!",
                                Toast.LENGTH_SHORT).show();
                    }
                    else
                    {
                        Toast.makeText(MainActivity.this, "Unable to delete",
                                Toast.LENGTH_SHORT).show();
                    }
                }
            }
        });
    }
}