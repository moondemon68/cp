#import <Foundation/Foundation.h>

int main(int argc, char *argv[]) {
    char s[105];
    scanf("%[^.]s", s);
    
    NSString *fileName = [[NSString alloc] initWithCString:s encoding:NSUTF8StringEncoding];
    NSString *filePath = [[NSBundle mainBundle] pathForResource:fileName ofType:@"json"];
    NSData *jsonData = [[NSData alloc] initWithContentsOfFile:filePath];
    
    // Write your code here. Print output to STDOUT
    
    return 0;
}