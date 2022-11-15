package com.example.practical_6_2_menu_option;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import android.graphics.Color;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    ConstraintLayout constraintLayout;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        constraintLayout = findViewById(R.id.cl);
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_example,menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        Toast.makeText(this, "Selected Item: " +item.getTitle(),
                Toast.LENGTH_SHORT).show();
        switch (item.getItemId())
        {
            case R.id.i1:
                constraintLayout.setBackgroundColor(Color.parseColor("#DD0000"));
                return true;
            case R.id.i2:
                constraintLayout.setBackgroundColor(Color.parseColor("#0000DD"));
                return true;
            case R.id.i3:
                constraintLayout.setBackgroundColor(Color.parseColor("#00DD00"));
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }
}
