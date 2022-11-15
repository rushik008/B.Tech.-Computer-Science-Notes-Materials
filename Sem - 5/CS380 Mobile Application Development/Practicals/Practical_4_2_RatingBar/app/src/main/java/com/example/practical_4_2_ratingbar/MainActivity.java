package com.example.practical_4_2_ratingbar;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RatingBar;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final RatingBar simpleRatingBar = (RatingBar) findViewById(R.id.simpleRatingBar);
        Button submitButton = (Button) findViewById(R.id.submitButton);

        submitButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String totalRating = "Total Rating: " + simpleRatingBar.getNumStars();
                String rating = "Rating: " + simpleRatingBar.getRating();
                Toast.makeText(getApplicationContext(), totalRating+ "\n" + rating, Toast.LENGTH_LONG).show();
            }
        });
    }
}
