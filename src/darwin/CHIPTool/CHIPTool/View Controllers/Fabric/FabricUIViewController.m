//
//  FabricUIViewController.m
//  CHIPTool
//
//  Created by Shana Azria on 15/04/2021.
//  Copyright © 2021 CHIP. All rights reserved.
//

#import "FabricUIViewController.h"

#import "CHIPUIViewUtils.h"
#import "DefaultsUtils.h"

@interface FabricUIViewController ()

@property (nonatomic, strong) UITextField * getFabricIDTextField;
@property (nonatomic, strong) UITextField * updateFabricLabelTextField;
@property (nonatomic, strong) UITextField * removeFabricTextField;

@property (nonatomic, strong) UITextView * fabricsListTextView;
@property (nonatomic, strong) UIStackView * stackView;

@property (readwrite) CHIPFabric * cluster;

@end


@implementation FabricUIViewController
// MARK: UIViewController methods

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self setupUIElements];

    // listen for taps to dismiss the keyboard
    UITapGestureRecognizer * tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(dismissKeyboard)];
    [self.view addGestureRecognizer:tap];

    self.cluster = [[CHIPFabric alloc] initWithDevice:CHIPGetPairedDevice() endpoint:1 queue:dispatch_get_main_queue()];
}

- (void)dismissKeyboard
{
    [self.getFabricIDTextField resignFirstResponder];
    [self.updateFabricLabelTextField resignFirstResponder];
    [self.removeFabricTextField resignFirstResponder];
}

// MARK: UI Setup

- (void)setupUIElements
{
    self.view.backgroundColor = UIColor.whiteColor;

    // Title
    UILabel * titleLabel = [CHIPUIViewUtils addTitle:@"Fabric" toView:self.view];

    // stack view
    _stackView = [UIStackView new];
    _stackView.axis = UILayoutConstraintAxisVertical;
    _stackView.distribution = UIStackViewDistributionEqualSpacing;
    _stackView.alignment = UIStackViewAlignmentLeading;
    _stackView.spacing = 30;
    [self.view addSubview:_stackView];

    _stackView.translatesAutoresizingMaskIntoConstraints = false;
    [_stackView.topAnchor constraintEqualToAnchor:titleLabel.bottomAnchor constant:30].active = YES;
    [_stackView.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor constant:30].active = YES;
    [_stackView.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor constant:-30].active = YES;

    // Get Fabric ID
    UIButton *getFabricIDButton = [UIButton new];
    [getFabricIDButton setTitle:@"Go" forState:UIControlStateNormal];
    [getFabricIDButton addTarget:self action:@selector(getFabricIDButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    _getFabricIDTextField = [UITextField new];
    _getFabricIDTextField.placeholder = @"Get FabricID";
    _getFabricIDTextField.userInteractionEnabled = false;
    UIView *getFabricIDView = [CHIPUIViewUtils viewWithUITextField:_getFabricIDTextField button:getFabricIDButton];
    [_stackView addArrangedSubview:getFabricIDView];

    getFabricIDView.translatesAutoresizingMaskIntoConstraints = false;
    [getFabricIDView.trailingAnchor constraintEqualToAnchor:_stackView.trailingAnchor].active = YES;
    
    // Update Fabric Label
    UIButton *updateFabricLabelButton = [UIButton new];
    [updateFabricLabelButton setTitle:@"Go" forState:UIControlStateNormal];
    [updateFabricLabelButton addTarget:self action:@selector(updateFabricLabelButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    _updateFabricLabelTextField = [UITextField new];
    _updateFabricLabelTextField.placeholder = @"Update Fabric Label";
    UIView *updateFabricLabelView = [CHIPUIViewUtils viewWithUITextField:_updateFabricLabelTextField button:updateFabricLabelButton];
    [_stackView addArrangedSubview:updateFabricLabelView];

    updateFabricLabelView.translatesAutoresizingMaskIntoConstraints = false;
    [updateFabricLabelView.trailingAnchor constraintEqualToAnchor:_stackView.trailingAnchor].active = YES;
    
    // Remove Fabric
    UIButton *removeFabricButton = [UIButton new];
    [removeFabricButton setTitle:@"Go" forState:UIControlStateNormal];
    [removeFabricButton addTarget:self action:@selector(removeFabricButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    _removeFabricTextField = [UITextField new];
    _removeFabricTextField.keyboardType = UIKeyboardTypeNumberPad;
    _removeFabricTextField.placeholder = @"FabricID to remove";
    UIView *removeFabricView = [CHIPUIViewUtils viewWithUITextField:_removeFabricTextField button:removeFabricButton];
    [_stackView addArrangedSubview:removeFabricView];

    removeFabricView.translatesAutoresizingMaskIntoConstraints = false;
    [removeFabricView.trailingAnchor constraintEqualToAnchor:_stackView.trailingAnchor].active = YES;
    
    UIButton *getFabricsListButton = [UIButton new];
    getFabricsListButton.titleLabel.font = [UIFont systemFontOfSize:17];
    getFabricsListButton.titleLabel.textColor = [UIColor blackColor];
    getFabricsListButton.layer.cornerRadius = 5;
    getFabricsListButton.clipsToBounds = YES;
    getFabricsListButton.backgroundColor = UIColor.systemBlueColor;
    [getFabricsListButton setTitle:@"Get Fabrics List" forState:UIControlStateNormal];
    [getFabricsListButton addTarget:self action:@selector(getFabricsListButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [_stackView addArrangedSubview:getFabricsListButton];
    
    getFabricsListButton.translatesAutoresizingMaskIntoConstraints = false;
    [getFabricsListButton.trailingAnchor constraintEqualToAnchor:_stackView.trailingAnchor].active = YES;
    [getFabricsListButton.leadingAnchor constraintEqualToAnchor:_stackView.leadingAnchor].active = YES;
    
    // Fabrics text view
    _fabricsListTextView = [UITextView new];
    _fabricsListTextView.font = [UIFont systemFontOfSize:14];
    _fabricsListTextView.textColor = [UIColor systemBlueColor];
    _fabricsListTextView.scrollEnabled = YES;
    _fabricsListTextView.text = @"";
    [self.view addSubview:_fabricsListTextView];
    
    _fabricsListTextView.translatesAutoresizingMaskIntoConstraints = false;
    [_fabricsListTextView.trailingAnchor constraintEqualToAnchor:_stackView.trailingAnchor].active = YES;
    [_fabricsListTextView.leadingAnchor constraintEqualToAnchor:_stackView.leadingAnchor].active = YES;
    [_fabricsListTextView.topAnchor constraintEqualToAnchor:_stackView.bottomAnchor constant:20].active = YES;
    [_fabricsListTextView.bottomAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.bottomAnchor constant:-30].active = YES;
    
    
}

- (IBAction)getFabricIDButtonPressed:(id)sender
{
    NSLog(@"Request to getFabricID");
    [self.cluster getFabricId:^(NSError * _Nullable error, NSDictionary * _Nullable values) {
        if (error) {
            NSLog(@"Got back error trying to getFabricId %@", error);
        } else {
            NSLog(@"Got back fabricID values %@", values);
            NSString *fabricID = [values objectForKey:@"fabricId"];
            if (fabricID)
            {
                dispatch_async(dispatch_get_main_queue(), ^{
                    self.getFabricIDTextField.text = [NSString stringWithFormat:@"%@", fabricID];
                });
            }
        }
        
    }];
}

- (IBAction)updateFabricLabelButtonPressed:(id)sender
{
    NSString *label = _updateFabricLabelTextField.text;
    NSLog(@"Request to updateFabricLabel %@", label);
    [self.cluster updateFabricLabel:[label dataUsingEncoding:NSUTF8StringEncoding] completionHandler:^(NSError * _Nullable error, NSDictionary * _Nullable values) {
        if (error) {
            NSLog(@"Got back error trying to updateFabricLabel %@", error);
        } else {
            NSLog(@"Successfully updated the label: %@", values);
        }
    }];
}

- (IBAction)removeFabricButtonPressed:(id)sender
{
//    NSString *fabricId = _removeFabricTextField.text;
//    NSNumberFormatter *numberFormatter = [[NSNumberFormatter alloc] init];
//    numberFormatter.numberStyle = NSNumberFormatterDecimalStyle;
//    NSNumber *fabricID = [numberFormatter numberFromString:fabricId];
   
}

- (IBAction)getFabricsListButtonPressed:(id)sender
{
    NSLog(@"Request to read Fabrics Lict");
    [self.cluster readAttributeFabricsList:^(NSError * _Nullable error, NSDictionary * _Nullable values) {
        NSMutableString *fabricsText = [NSMutableString new];
        if (error) {
            NSLog(@"Got back error trying to read fabrics list %@", error);
            [fabricsText appendString:[NSString stringWithFormat:@"Error: %@ /n", [error description]]];
        } else {
            NSDictionary *fabricsList = [values objectForKey:@"value"];
            NSLog(@"got back fabrics list: %@", values);
            for (NSDictionary *fabricDict in fabricsList)
            {
                NSNumber *fabricId = [fabricDict objectForKey:@"FabricId"];
                NSNumber *nodeID = [fabricDict objectForKey:@"NodeId"];
                NSNumber *vendorID = [fabricDict objectForKey:@"VendorId"];
                NSData *labelData = [fabricDict objectForKey:@"label"];
                
                NSString* label = [[NSString alloc] initWithData:labelData encoding:NSUTF8StringEncoding];
                [fabricsText appendString:[NSString stringWithFormat:@"FabricId: %@\n", fabricId]];
                [fabricsText appendString:[NSString stringWithFormat:@"NodeId: %@\n", nodeID]];
                [fabricsText appendString:[NSString stringWithFormat:@"VendorId: %@\n", vendorID]];
                [fabricsText appendString:[NSString stringWithFormat:@"FabricLabel: %@\n", [label length] > 0 ? label : @"not set"]];
                [fabricsText appendString:@"------"];
            }
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            self->_fabricsListTextView.text = fabricsText;
        });
        
    }];
}



@end
