package com.example.practical_4_1_seekbar;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.SeekBar;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    Button submitButton;
    SeekBar simpleSeekBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    setContentView(R.layout.activity_main);
    // initiate  views
    simpleSeekBar=(SeekBar)

    findViewById(R.id.simpleSeekBar);
    // perform seek bar change listener event used for getting the progress value
        simpleSeekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener()

    {
        int progressChangedValue = 0;
        public void onProgressChanged (SeekBar seekBar,int progress, boolean fromUser){
        progressChangedValue = progress;
    }
        public void onStartTrackingTouch (SeekBar seekBar){
        // TODO Auto-generated method stub
        }

        public void onStopTrackingTouch (SeekBar seekBar) {
            Toast.makeText(MainActivity.this, "Seek bar progress is :" + progressChangedValue,
                    Toast.LENGTH_SHORT).show();
        }

    });
    }
}

