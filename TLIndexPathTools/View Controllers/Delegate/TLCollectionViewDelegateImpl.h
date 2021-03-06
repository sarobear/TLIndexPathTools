//
//  TLCollectionViewDelegateImpl.h
//
//  Copyright (c) 2013 Tim Moose (http://tractablelabs.com)
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <UIKit/UIKit.h>
#import "TLIndexPathDataModel.h"

/**
 Minimal implementation of `UICollectionViewDataSource` & `UICollectionViewDelegate`. Can
 be set as the delegate and data source directly or other delegates and data sources
 can forward messages (see, for example `TLCollectionViewController`).
 */

@interface TLCollectionViewDelegateImpl : NSObject <UICollectionViewDataSource, UICollectionViewDelegate>

/**
 Client code must set this block before any delegate methods are called. The block
 is responsible for returning the data model for the given tableView.
 */
@property (strong, nonatomic) TLIndexPathDataModel *(^dataModelProvider)(UICollectionView *collectionView);

/**
 The implementation of `collectionView:cellForItemAtIndexPath:` calls this method
 to ask for the cell's identifier before attempting to dequeue a cell. The default
 implementation of this method first asks the data model for an identifier and,
 if none is provided, returns the "Cell". Data models that don't use
 `TLIndexPathItem` as their item type typically return `nil` and so it is not
 uncommon to override this method with custom logic.
 */
- (NSString *)collectionView:(UICollectionView *)collectionView cellIdentifierAtIndexPath:(NSIndexPath *)indexPath;

/*
 This method is intended to be overridden with the cell's configuration logic.
 It is called by by this classes implementation of `collectionView:cellForItemAtIndexPath:`
 after the cell has been created/dequeued. The default implementation does nothing.
 
 Alternatively, one can override `collectionView:cellForItemAtIndexPath:` and either
 call the super implementation to get the unconfigured cell or or create/dequeue
 the cell directly.
 */
- (void)collectionView:(UICollectionView *)collectionView configureCell:(UICollectionViewCell *)cell atIndexPath:(NSIndexPath *)indexPath;

@end
