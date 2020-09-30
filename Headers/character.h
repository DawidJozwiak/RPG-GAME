#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{       
    public:

        int max_health;
        int max_stamina;
        int current_health = 0;
        int current_stamina;
        int weapon_damage = 0;
        int armor_coefficient = 1;
        bool status = false;
        int class_number;
        float classCoefficient = 1;
        int health;

public:
        virtual int Damage(int current_health, float coef);

        virtual int Skill(float eh, float yhn, int st, float ah, int ls);


        int getMax_health();
        void setMax_health(int value);
        int getMax_stamina() const;
        void setMax_stamina(int value);
        int getCurrent_health();
        void setCurrent_health(int value);
        int getCurrent_stamina() const;
        void setCurrent_stamina(int value);
        double getTaken_Damage() const;
        void setTaken_Damage(double value);
        int getWeapon_damage() const;
        void setWeapon_damage(int value);
        int getArmor_coefficient() const;
        void setArmor_coefficient(int value);
        int getClass_number() const;
        void setClass_number(int value);
        float getClassCoefficient() const;
        void setClassCoefficient(float value);
        bool getStatus() const;
        void setStatus(bool value);
        int getHealth() const;
        void setHealth(int value);
};

#endif // CHARACTER_H
