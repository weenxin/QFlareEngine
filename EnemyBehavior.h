#ifndef ENEMYBEHAVIOR_H
#define ENEMYBEHAVIOR_H


class Enemy;


class EnemyBehavior
{
protected:
    Enemy *e;
public:
    explicit EnemyBehavior(Enemy *_e);
    virtual ~EnemyBehavior();
    virtual void logic();
};

#endif // ENEMYBEHAVIOR_H
