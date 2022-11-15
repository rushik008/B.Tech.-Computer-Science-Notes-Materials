package com.example.practical_9_sql_db;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DBHelper extends SQLiteOpenHelper {
    public DBHelper(Context context)
    {
        super(context, "Userdata.db", null, 1);
    }
    @Override
    public void onCreate(SQLiteDatabase DB) {
        DB.execSQL("create table users(id TEXT primary key, name TEXT, surname TEXT, marks TEXT)");
    }
    @Override
    public void onUpgrade(SQLiteDatabase DB, int i, int i1) {
        DB.execSQL("drop table if exists users");
    }
    public Boolean InsertData(String id, String name, String surname, String marks)
    {
        SQLiteDatabase DB = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put("id",id);
        contentValues.put("name",name);
        contentValues.put("surname",surname);
        contentValues.put("marks",marks);
        long res = DB.insert("users",null,contentValues);
        if(res==-1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    public Boolean UpdateDate(String id, String name, String surname, String marks)
    {
        SQLiteDatabase DB = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put("id",id);
        contentValues.put("name",name);
        contentValues.put("surname",surname);
        contentValues.put("marks",marks);
        Cursor cursor = DB.rawQuery("select * from users where id=?", new String[]{id});
        if(cursor.getCount()>0)
        {
            long res = DB.update("users", contentValues, "id=?",new String[]{id});
            if(res==-1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    public Boolean DeleteDate(String id)
    {
        SQLiteDatabase DB= this.getWritableDatabase();
        Cursor cursor =DB.rawQuery("Select * from users where id=?", new String[]{id} );
        if (cursor.getCount()>0)
        {
            long result = DB.delete("users", "id=?",new String[]{id});
            if(result==-1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    public Cursor ViewData()
    {
        SQLiteDatabase DB = this.getWritableDatabase();
        Cursor cursor = DB.rawQuery("select * from users",null);
        return cursor;
    }
}