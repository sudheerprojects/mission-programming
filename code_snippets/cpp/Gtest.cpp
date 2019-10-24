#include <gtest/gtest.h>

class BankAcount
{
private:
    int balance;
public:
    BankAccount():balance(0){};
    explicit BankAcount(const int& amount): balance(amount){}; 
    void deposit(int amount)
    {
        balance += amount;
    }
    bool withdraw(int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            return true;
        }
        return false;
    }
    int getBalance()
    {
        return balance;
    } 
    void setBalance(int balance)
    {
         balance = amount;
    }
}

class BankAcountTest: testing::Test
{
    BankAcountTest()
    {
        std::unique_ptr<BankAccount> accountUP(new BankAcount());
    }
    virtual ~BankAcountTest()
    {
        accountUP.release()
    }
}

TEST_F(BankAccountTest, zeroBalanceAccountTest)
{
    EXPECT_EQ(0, accoutUP->getBalance());
}

TEST_F(BankAccountTest, depositAccountTest)
{
    accountUP->deposit(100);
    EXPECT_EQ(100, accountUP->getBalance());
}

struct AccountState
{
    int initialBalace;
    int withdrawAmount;
    int finalBalance;
    bool success;
}

class WithdrawAccountTest: BankAccountTest, testing::withParamInterface<AccountState>
{
    WithdrawAccountTest()
    {
        accountUP->deposit(GetParam().initialBalance);
    }
}

TEST_P(WithdrawAccountTest, FinalBalance)
{
    auto as = GetParam();
    bool status = accountUP->withdraw(as.withdrawamount);
    EXPECT_EQ(as.finalBalance, accountUP->getBalance());
    EXPECT_EQ(as.success, status);
}

INSTANTIATE_TEST_CASE_P(Default, WithdrawAccountTest, 
        testing::Values(
        AccountState{100, 50, 50 true),
        AccountState{100, 200, 100, false}
        ));

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TEST();
}